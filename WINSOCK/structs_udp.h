#include <winsock.h>
struct conn
{
  int id;
};

struct partida
{
  int id;
  struct sockaddr_in ip;
  char juego[50];
  int numero;
};

struct resultado {
  int id;
  int ganador;
};

struct pkt {
  int tipo;
  union {struct conn conn; struct partida partida; struct resultado resulado;};
};
