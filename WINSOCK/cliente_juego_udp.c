#include <stdio.h>
#include "WinSock2.h"
#include "structs_udp.h"

int main (int argc, char** argv){
  WSADATA wsa;
  SOCKET sock, sock_c;
  struct sockaddr_in ip;
  char buffer[1024];
  struct pkt pkt;
  
  if (WSAStartup(MAKEWORD(2,0),&wsa)) {
    printf("\nError Carga WSA");
    return 1;
  }
  sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr(argv[0]);
  ip.sin_port = htons(atoi(argv[1]));
  
  connect(sock,(SOCKADDR*)&ip,sizeof(ip));
  memset(buffer,0,sizeof(buffer));
  recv(sock_c,buffer,sizeof(buffer),0);
  printf("\nRecibido: %s", buffer);

  memset(&pkt,0,sizeof(pkt));
  pkt.tipo = 1;
  sendto(sock,(char*)&pkt,sizeof(pkt),0,(SOCKADDR*)&ip,sizeof(ip));
  recvfrom(sock,(char*)&pkt,sizeof(pkt),0,NULL,NULL);

  if (pkt.tipo == 1) {
    pkt.tipo = 4;
    sendto(sock,(char *)&pkt,sizeof(pkt),0,(SOCKADDR*)&pkt.partida.ip,sizeof(ip));

  } else if (pkt.tipo == 4) {
    printf("\nNumero magico: ");
    scanf("%d", &pkt.partida.numero);
    sendto(sock,(char *)&pkt,sizeof(pkt),0,(SOCKADDR*)&pkt.partida.ip,sizeof(ip));
  }
  
  

  while (1) {
    memset(buffer,0,sizeof(buffer));
    printf("\nCliente: ");
    fgets(buffer,sizeof(buffer),stdin);
    send(sock,buffer,strlen(buffer),0);
  }
  
  printf("\nCarga WSA buena");
  return 0;
}