#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

#define LOGIN_USER_ON 1
#define LOGIN_USER_OFF 0

int login_status=LOGIN_USER_OFF;
char username[25];

int check_if_logged()
{
    if(login_status==LOGIN_USER_ON)
        return 1;
    else return 0;
}

int interpretare_mesaj(char msg[1024])
{
    int i,j=1;
    char * pch;
    pch = strtok (msg," ");
    if(strcmp(pch,"mystat")==0)
        return 1;
    if(strcmp(pch,"login")==0)
        return 3;
    if(strcmp(pch,"myfind")==0)
        return 2;
    if(strcmp(pch,"quit")==0)
        return 4;
    return 0;
}

void file_status(char msg[1024])
{
    char * pch;
    pch = strtok (msg," ");
    pch=strtok(NULL,msg);
    struct stat sb;
    
    if (stat(pch, &sb) == -1) {
        perror(pch);
        exit(EXIT_FAILURE);
    }
    
    printf("File type:                ");
    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }
    
    printf("I-node number:            %ld\n", (long) sb.st_ino);
    
    printf("Mode:                     %lo (octal)\n",
           (unsigned long) sb.st_mode);
    
    printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
           (long) sb.st_uid, (long) sb.st_gid);
    
    printf("Preferred I/O block size: %ld bytes\n",
           (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",
           (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",
           (long long) sb.st_blocks);
    
    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s \n", ctime(&sb.st_mtime));
}

void logare()
{
    char user_introdus[10], user_citit[10];
    FILE * fp;
    
    fp = fopen ("username.txt", "w+");
    fscanf(fp, "%s", user_introdus);
    printf("%s","Username:");
    scanf("%s",user_citit);
    
    if(strcmp(user_citit,user_introdus)!=0)
        printf("%s \n","Userul introdus nu exista!");
    
    fclose(fp);
}

int main() 
{
    int sockp[2], child;
    char msg[1024],cmsg[1024];
    
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockp) < 0)
    {
        perror("Err... socketpair");
    }
    
    if ((child = fork()) == -1) perror("Error fork");
    else
        if (child)
        {
            close(sockp[0]);
            printf("%s","Introduceti comanda:");
            scanf("%[^\n]s",msg);
            if (write(sockp[1], msg, sizeof(msg)) < 0) perror("[parinte]Err...write");
            close(sockp[1]);
        }
        else 
        {
            close(sockp[1]);
            if (write(sockp[0], msg, sizeof(msg)) < 0) perror("[copil]Err...write");
            if (read(sockp[0], msg, 1024) < 0)  perror("[copil]Err..read");
            strcpy(cmsg,msg);
            switch(interpretare_mesaj(cmsg)){
                case 1:
                    file_status(msg);
                case 2:
                    
                case 3:
                    logare();
                case 4:
                    return 0;
            }
            close(sockp[0]);
        }
}
