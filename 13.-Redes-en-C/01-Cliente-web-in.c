#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /*Definiciones básicas para el socket*/
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <arpa/inet.h>
#include <stdarg.h> /*Para la función de errores*/
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define SERVER_PORT 80

#define MAXLINE 4096
#define SA struct sockaddr

void err_n_die(const char *fmt, ...);



int main(int argc, char **argv)
{
    int sockfd, n;
    int sendbytes;

    struct sockaddr_in servaddr;

    char sendline[MAXLINE];
    char recvline[MAXLINE];

    if (argc != 2)
        err_n_die("Uso: %s <IPaddress>", argv[0]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_n_die("Error al crear el socket");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err_n_die("Error en %s", argv[1]);

    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
        err_n_die("¡Error el conectar!");

    //Conectado al servidor, ahora enviamos la petición
    sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
    sendbytes = strlen(sendline);

    if (write(sockfd, sendline, sendbytes) != sendbytes)
        err_n_die("Error al escribir en el socket");

    memset(recvline, 0, MAXLINE);

    //Leemos la respuesta del servidor
    while ((n = read(sockfd, recvline, MAXLINE - 1)) > 0)
    {
        printf("%s", recvline);
    }

    if (n < 0)
        err_n_die("Error al leer del socket");


    exit(0);
}

void err_n_die(const char *fmt, ...)
{
    int errno_save;
    va_list ap;

    errno_save = errno;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    fflush(stdout);

    if (errno_save != 0)
    {
        fprintf(stdout, "(errno = %d) : %s\n", errno_save,
        strerror(errno_save));
        fprintf(stdout, "\n");
        fflush(stdout);
    }

    va_end(ap);

    exit(1);

}