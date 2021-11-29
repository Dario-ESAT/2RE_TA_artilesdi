#include <stdio.h>
#include <winsock.h>
int main(){
  WSADATA wsa;
  struct timeval tv;
  SOCKET sock;
  struct sockaddr_in ip;
  fd_set readfs;
  char buffer[1024];
  int clientes = 0;

  int ip_size = sizeof(ip);
  return 0;
}