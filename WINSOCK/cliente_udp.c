#include <stdio.h>
#include <winsock.h>

int main(int argc, char**argv){
  WSADATA wsa;
  SOCKET sock;
  
  struct sockaddr_in ip;
  char buffer[1024];
  
  WSAStartup(MAKEWORD(2,0),&wsa);
  
  sock = socket(AF_INET,SOCK_DGRAM, IPPROTO_UDP);
  
  if (argc != 2) {
    printf("\nERROR:Sintaxis server.exe puerto\n");
    return 1;
  }
  
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr("127.0.0.1");
  ip.sin_port = htons(atoi(argv[1]));
 
  while (1) {
    printf("\nCadena: ");
    memset(buffer,0,sizeof(buffer));
    fgets(buffer,sizeof(buffer),stdin);
    sendto(sock,buffer,sizeof(buffer),0,(SOCKADDR*)&ip, sizeof(ip));
    memset(buffer,0,sizeof(buffer));
    recvfrom(sock,buffer,sizeof(buffer),0,NULL,NULL);
    printf("\nRecibido:%s",buffer);
  }
  
  return 0;
}