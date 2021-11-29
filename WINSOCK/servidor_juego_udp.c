#include <stdio.h>
#include <winsock.h>
#include "structs_udp.h"
int main(int argc, char**argv){
  WSADATA wsa;
  SOCKET sock;
  struct sockaddr_in ip,ipc[10];
  int ip_size = sizeof(ip);
  char buffer[1024];
  int clientes = 0;
  int i;
  struct pkt pkt;
  WSAStartup(MAKEWORD(2,0),&wsa);
  sock = socket(AF_INET,SOCK_DGRAM, IPPROTO_UDP);
  if (argc != 2) {
    printf("\nERROR:Sintaxis server.exe puerto\n");
    return 1;
  }
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr("127.0.0.1");
  ip.sin_port = htons(atoi(argv[1]));

  if (bind(sock,(SOCKADDR*)&ip, ip_size)) {
    printf("Error de Unión");
    return 1;
  }
  
  if (listen(sock,SOMAXCONN)) {
    printf("Error de escucha");
    return 1;
  }


  while (1) {
    memset(buffer,0,sizeof(buffer));
    recvfrom(sock,buffer,sizeof(buffer),0,(SOCKADDR*)&ipc[clientes],&ip_size);
    if (pkt.tipo == 1) {
      printf("\nNuevo cliente..");
      if (clientes == 2) {
        printf("\nEmpieza la partida");
      } else {
        printf("\nEsperando oponente");
      }
      
    } else {
      printf("\nEsperando oponente");
    }
    for (i = 0; i < clientes; i++) {
      printf("\nEl ganador de la patida %d ha sido %d", pkt.resulado.id, pkt.resulado.ganador);
    }
  }
  
  return 0;
}