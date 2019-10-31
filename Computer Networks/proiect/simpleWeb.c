/* 
   simpleWeb.cpp - Simple Web Server concurent
   Accepta drept client un browser prin protocolul HTML si
   ii "serveste" clientului un fisier HTML/TXT
   folosind protocolul TCP
   Autor: Radu Emilian <mihai.radu@info.uaic.ro> (c)2019
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/stat.h>

#define ERROR -1

/* numar maxim de clienti */
#define MAXCL 5

/* nr maxim de biti */
#define MAXDAT 1024

/* cate tipuri de fisiere accepta */
#define TYPE_FILE 4

/* adresa fisierului de configurare */
#define PATH_DOC 512

/* specifice protocolului HTML */
#define NOT_FOUND 404
#define BAD_VERSION 4042

/* codul de eroare returnat de anumite apeluri */
extern int errno;

/* toate configurarile se fac in fisierul conf.txt */
struct configFile
{
    int port;                     // portul serverului
    char address[PATH_DOC];       // calea absoluta a locatiei serverului
    char request[MAXDAT][MAXDAT]; // ce fisier cere clientul
    char send[MAXDAT][MAXDAT];    // ce fisier trimite serverul
    char default_page[MAXDAT];    // pagina default care o sa ii apara clientului cand scrie ip-ul urmat de port in browser fara sa fie specificata o alta cale de fisier
};

/* request-uri primite de la client */
struct htmlrequest
{
    char *full, *url, *version, *method;
};

/* declaram functiile folosite */
/* server_setup citeste configFile si printeaza informatiile de baza ale serverului */
void server_setup(struct configFile *config);
/* pentru a servi pagina web unui client */
void get_client(int client, struct configFile *config);
/* pentru a rezolva cerinta clientului */
void send_request(int client, struct htmlrequest *request, struct configFile *config);

int main(int argc, char **argv)
{
    struct sockaddr_in server, from; // structura folosita de server
    struct configFile config;        // fisierul de configurare
    int sd, pid;                     //descriptorul de socket

    /* configurarea serverului */
    server_setup(&config);
    printf("[SERVER] Adresa serverului: %s\n", config.address);
    printf("[SERVER] Portul: %d\n", config.port);
    printf("[SERVER] Pagina de index: %s\n", config.default_page);

    /* pregatirea structurilor de date */
    bzero(&from, sizeof(from));
    bzero(&server, sizeof(server));

    /* umplem structura folosita de server */
    /* stabilirea familiei de socket-uri */
    server.sin_family = AF_INET;
    /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    /* utilizam un port utilizator */
    server.sin_port = htons(config.port);

    /* crearea unui socket */
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR)
    {
        perror("[SERVER] Eroare la socket().\n");
        return errno;
    }

    /* atasam socketul */
    if (bind(sd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == ERROR)
    {
        perror("[SERVER] Eroare la bind().\n");
        return errno;
    }

    /* punem serverul sa asculte daca vin clienti sa se conecteze */
    if (listen(sd, MAXCL) == ERROR)
    {
        perror("[SERVER] Eroare la listen().\n");
        return errno;
    }

    /* servim in mod concurent clientii... */
    while (1)
    {
        int length = sizeof(from);
        int client;

        printf("[SERVER] Asteptam clienti la portul %d...\n", config.port);
        fflush(stdout);

        /* acceptam un client (stare blocanta pana la realizarea conexiunii) */
        client = accept(sd, (struct sockaddr *)&from, (socklen_t *)&length);

        /* eroare la acceptarea conexiunii de la un client */
        if (client < 0)
        {
            perror("[server]Eroare la accept().\n");
            continue;
        }
        /* eroare la fork */
        if ((pid = fork()) == ERROR)
        {
            perror("[SERVER] Eroare la fork(). \n");
        }
        if (pid == 0)
        {
            /* s-a realizat conexiunea, se astepta request-ul */
            get_client(client, &config);

            printf("[SERVER] Acceptam clientul %d.\n", client);
            fflush(stdout);

            /* am terminat cu acest client, inchidem conexiunea */
            close(client);
            exit(0);
        }
        else
        {
            close(client);
            while (waitpid(-1, NULL, WNOHANG) >= 0)
                ;
        }
    }
}

void server_setup(struct configFile *config)
{
    int length;                                            // linia la care s-a ajuns in fisierul de configurare
    char *absolute_path;                                   // pentru calea site-ului
    char buffer[MAXDAT], path_file[MAXDAT], rline[MAXDAT]; // adresa fisierului si linia care o sa se citeasca din fisierul de configurare
    char *buff;                                            // pentru citirea din fisier

    absolute_path = getcwd(buffer, MAXDAT); // getcwd ia calea folderului
    strcpy(path_file, absolute_path);
    strcat(path_file, "/config.txt"); // fisierul de configurare este la adresa "../config.txt"

    FILE *file_config;
    file_config = fopen(path_file, "r");
    
    /* verificam daca s-a deschis fisierul */
    if (file_config == NULL)
    {
        perror("[SERVER] Eroare la deschiderea fisierului de configurare: ");
        exit(ERROR);
    }

    /* toate informatiile din fisierul de configurare se atribuie bufferului buff */
    if (file_config)
    {
        fseek(file_config, 0, SEEK_END);
        length = ftell(file_config);
        buff = malloc(length);
        fseek(file_config, 0, SEEK_SET);
        if (buff)
            fread(buff, 1, length, file_config);
        fclose(file_config);
    }
    /* daca exista informatii in fisier */
    if (buff)
    {
        /* preluarea portului */
        char *token, *way, *back;
        token = strtok_r(buff, " ", &way);
        config->port = atoi(way);

        /* preluarea adresei site-ului */
        token = strtok_r(NULL, " ", &way);
        token = strtok_r(NULL, " ", &way);
        strcpy(config->address, token);

        /* preluarea paginii de index */
        token = strtok_r(NULL, " ", &way);
        token = strtok_r(NULL, " ", &way);
        strcpy(config->default_page, token);

        /* preluarea extensiilor fisierelor
        HTML */
        token = strtok_r(NULL, "\n", &way);
        back = strstr(token, " ");
        back = strtok(back, " ");
        token = strtok(token, " ");
        strcpy(config->send[0], back);
        strcpy(config->request[0], token);

        // TXT
        token = strtok_r(NULL, "\n", &way);
        back = strstr(token, " ");
        back = strtok(back, " ");
        token = strtok(token, " ");
        strcpy(config->send[1], back);
        strcpy(config->request[1], token);

        // PNG
        token = strtok_r(NULL, "\n", &way);
        back = strstr(token, " ");
        back = strtok(back, " ");
        token = strtok(token, " ");
        strcpy(config->send[2], back);
        strcpy(config->request[2], token);

        // JPG
        token = strtok_r(NULL, "\n", &way);
        back = strstr(token, " ");
        back = strtok(back, " ");
        token = strtok(token, " ");
        strcpy(config->send[3], back);
        strcpy(config->request[3], token);
    }
}

void get_client(int client, struct configFile *config)
{
    int data_length;            // lungimea cererii html de la client
    char recv_data[MAXDAT];     // request-ul clientului transformat in string
    struct htmlrequest request; // structura in care salvam cererea clientului (versiune,url,etc.)

    /* salvam datele primite de la client */
    if ((data_length = recv(client, recv_data, MAXDAT, 0)) < 0)
    {
        perror("[SERVER] Eroare la primirea datelor despre client.");
        exit(ERROR);
    }

    /* daca exista separam string-ul recv_data astfel incat sa avem in structura toate informatiile necesare serverului */
    if (data_length)
    {
        char *location, *token; // locatia reprezinta locatia actuala la care am ajuns in string, token-ul separa string-ul in cuvinte

        /* luam intreg request-ul */
        token = strtok_r((char *)recv_data, "\n", &location);
        strcpy(request.full, token);
        printf("[CLIENT] Request Complet: %s\n", request.full);

        /* separam din request doar metoda utilizata de client (usually GET) */
        token = strtok_r((char *)recv_data, " ", &location);
        request.method = malloc(strlen(token) + 1);
        strcpy(request.method, token);
        printf("[CLIENT] Cerere tip: %s\n", request.method);

        /* in acelasi mod luam url-ul (URI) */
        token = strtok_r(NULL, " ", &location);
        request.url = malloc(strlen(token) + 1);
        strcpy(request.url, token);
        printf("[CLIENT] Adresa client: %s\n", request.url);

        /* si versiunea de HTML ceruta */
        request.version = malloc(strlen(location) + 1);
        strcpy(request.version, location);
        printf("[CLIENT] Versiune: %s\n", request.version);
    }
    /* rezolvam request-ul */
    send_request(client, &request, config);
    /* curatam pentru clientii urmatori */
    free(request.full);
    free(request.url);
    free(request.method);
    free(request.version);
}

void send_request(int client, struct htmlrequest *request, struct configFile *config)
{
    char path[PATH_DOC], *buff;          // pentru calea de acces catre fisier/buffer de citire
    int length;                          // lungimea textului din fisier
    size_t read_bytes, total_read_bytes; // citirea bytilor din fisier
    FILE *page;                          // fisierul din care se va citi
    int url = 0; // pentru a determina daca este sau nu introdus ceva in url
    char *extens; // daca este introdus se va extrage extensia .* fisierului

    /* calea absoluta la care se va adauga fisierul cerut */
    strcpy(path, config->address);

    /* declarari pt protocolul HTML */
    char html[] = "HTTP/1.1 200 OK:\r\n"
                       "Content-Type: text/html; charset=UTF-8\r\n\r\n";
    char txt[] = "HTTP/1.1 200 OK:\r\n"
                           "Content-Type: text/plain; charset=UTF-8\r\n\r\n";
    char jpg[] = "HTTP/1.1 200 OK:\r\n"
                          "Content-Type: image/jpeg; charset=UTF-8\r\n\r\n";
    char png[] = "HTTP/1.1 200 OK:\r\n"
                          "Content-Type: image/png; charset=UTF-8\r\n\r\n";
    char nfound[] = "HTTP/1.1 404 Not Found:%s\r\n"
                       "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                       "<!DOCTYPE html><html><head><title>404 Not Found</title>"
                       "<body><h1>404 Not Found</h1></body></html>\r\n";

    /* daca nu este introdus nimic dupa / se va afisa pagina default stabilita in fisierul de configurare */
    if (strcmp(request->url, "/") == 0)
    {
        strcat(path, "/");
        strcat(path, config->default_page);
    }
    /* daca nu se va prelua cerinta clientului */
    else
    {
        url = 1;
        extens = strstr(request->url, ".");
        strcat(path, request->url);
    }
    page = fopen(path, "r");
    /* verificarea 404 */
    if (page == NULL)
        write(client, nfound, sizeof(nfound));

    /* daca fisierul exista se va parsa la client */
    if (page)
    {
        fseek(page, 0, SEEK_END); // ponter la sfarsitul fisierului
        length = ftell(page);     // toti bitii din fisier
        buff = malloc(length);    // se acorda memorie bufferului
        fseek(page, 0, SEEK_SET);

        /* se trimite text/html */
        if (url == 1)
        {
            if (strcmp(extens, ".html") == 0 || strcmp(extens, "") == 0)
                send(client, html, sizeof(html) - 1, 0);
            if (strcmp(extens, ".txt") == 0)
                send(client, txt, sizeof(txt) - 1, 0);
            if (strcmp(extens, ".jpg") == 0)
                send(client, jpg, sizeof(jpg) - 1, 0);
            if (strcmp(extens, ".png") == 0)
                send(client, png, sizeof(png) - 1, 0);
        }
        if (url == 0)
            send(client, html, sizeof(html) - 1, 0);

        /* se trimite restul fisierului */
        total_read_bytes = 0;
        if (buff)
        {
            read_bytes = fread(buff, 1, MAXDAT*MAXDAT, page);
            total_read_bytes += read_bytes;
            send(client, buff, read_bytes, 0);
        }
        fclose(page); // inchidem fisierul cerut de client
    }
}
