#include <stdio.h>

//Libs para conecxão e tratamento de erros, na comunicação do socket.
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <resolv.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (void){
        int sock;
        int conn;

        struct sockaddr_in alvo;
        //Montando a conecção com o socket
        sock = socket(AF_INET,SOCK_STREAM,0);

        //Configurando o sock
        alvo.sin_family = AF_INET; //Para resolver ips AF_INET
        alvo.sin_port = htons(3000); //Definindo porta
        alvo.sin_addr.s_addr = inet_addr("IPS"); //Configurando o IP alvo para conectar!


        conn = connect(sock, (struct sockaddr *)&alvo, sizeof alvo);
        //Conectando o sock
        // sock -> Conecção AF_INET SOCK_STREAM para conecxão com a internet
        // struct -> Referência para a estrutura de dados struct
        // sizeof -> passando o tamanho do alvo

        if(conn == 0){
                printf("Porta Aberta!\n\n");
                close(sock);
                close(conn);
        }else{
                printf("Porta Fechada!\n\n");
        }
}
