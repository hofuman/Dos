#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

if(argc < 3){
        printf("Modo de uso IP PORT: 192.168.1.1 21");
        return 1;
}else{
        int meusocket;
        int conecta;
        int pacote = 0;
        int pacotes = 10000;
        int porta = atoi(argv[2]);
        char *destino;
        destino = argv[1];


        struct  sockaddr_in alvo;

        for(pacote = 1; pacote<pacotes; pacote++){

                meusocket =  socket(AF_INET,SOCK_STREAM,0);
                alvo.sin_family = AF_INET;
                alvo.sin_port = htons(porta);
                alvo.sin_addr.s_addr = inet_addr(destino);
                conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);
                if(conecta == 0){
                        printf("Porta %d - status [ %i PACOTE ENVIADO!]\n",porta,pacote);
                }else{
                      
                        printf("Erro de conexão...");
                }
        }

        }
}
