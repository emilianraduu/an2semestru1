#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

#define FIFO_NAME "fifo"

int main()
{
    pid_t pid;
    int rv;
    char s[300];
    int num, fd;
    fd = create(FIFO_NAME);
    
    printf("%d", fd);
    
    
    switch(pid=fork()) {
        case -1:
            perror("fork");
            exit(1);
            
        case 0:
            printf(" PC: Proces Copil!\n");
            printf(" PC: Am PID-ul %d\n", getpid());
            printf(" PC: PID-ul parintelui este %d\n", getppid());
            printf(" PC: Da-mi un status de iesire: ");
            
            mknod(FIFO_NAME, S_IFIFO | 0666, 0);
            
            printf("Astept sa scrie cineva...\n");
            
            printf("A venit cineva:\n");
            
            do {
                if ((num = read(fd, s, 300)) == -1)
                    perror("Eroare la citirea din FIFO!");
                else {
                    s[num] = '\0';
                    printf("S-au citit din FIFO %d bytes: \"%s\"\n", num, s);
                }
            } while (num > 0);
            scanf(" %d", &rv);
            printf(" PC: Am plecat!\n");
            exit(rv);
            
        default:
            printf("PP: Proces Parinte!\n");
            printf("PP: Am PID-ul %d\n", getpid());
            printf("PP: Am copil cu pidul %d\n", pid);
            printf("PP: Astept ca PC sa apeleze exit()...\n");

            printf("Astept cititori...\n");
        
            printf("Am un cititor....introduceti ceva..\n");
            
            while (gets(s), !feof(stdin)) {
                if ((num = write(fd, s, strlen(s))) == -1)
                    perror("Problema la scriere in FIFO!");
                else
                    printf("S-au scris in FIFO %d bytes\n", num);
            }
            wait(&rv);
            printf("PP: Statusul de iesire al PC este: %d\n", WEXITSTATUS(rv));
            printf("PP: Am plecat!\n");
    }
}
