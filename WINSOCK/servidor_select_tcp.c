#include <stdio.h>
#include <winsock.h>
int main(){
  WSADATA wsa;
  struct timeval tv;
  SOCKET sock,sock_c[10];
  struct sockaddr_in ip;
  fd_set readfs;
  char buffer[1024];
  int clientes = 0;

  int ip_size = sizeof(ip);
  int i;
  WSAStartup(MAKEWORD(2,0),&wsa);
  sock = socket(AF_INET,SOCK_DGRAM, IPPROTO_UDP);
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr("127.0.0.1");
  ip.sin_port = htons(9999);

  bind(sock,(SOCKADDR*)&ip, ip_size);
  
  listen(sock,SOMAXCONN);
  tv.tv_sec  =2 ;
  tv.tv_usec = 0;
  while (1) {
    FD_ZERO(&readfs);
    FD_SET(sock, &readfs);
    select(clientes,&readfs,NULL,NULL, &tv);
    if (FD_ISSET(sock,&readfs)) {
      printf("\nNueva Conexión");
      sock_c[clientes] = accept(sock,NULL,NULL);
      clientes++;
    }
    
  }
  
  return 0;
}