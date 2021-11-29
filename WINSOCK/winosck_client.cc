#include <stdio.h>
#include "WinSock2.h"

int main (int argc, char** argv){
  WSADATA wsa;
  SOCKET sock, sock_c;
  struct sockaddr_in ip;
  char buffer[1024];
  
  if (WSAStartup(MAKEWORD(2,0),&wsa)) {
    printf("\nError Carga WSA");
    return 1;
  }
  sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr("127.0.0.1");
  ip.sin_port = htons(7979);
  
  connect(sock,(SOCKADDR*)&ip,sizeof(ip));
  memset(buffer,0,sizeof(buffer));
  recv(sock_c,buffer,sizeof(buffer),0);
  printf("\nRecibido: %s", buffer);
  
  while (1) {
    memset(buffer,0,sizeof(buffer));
    printf("\nCliente: ");
    fgets(buffer,sizeof(buffer),stdin);
    send(sock,buffer,strlen(buffer),0);
  }
  
  printf("\nCarga WSA buena");
  return 0;
}