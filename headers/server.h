#ifndef SERVER_H_   /* Include guard */
#define SERVER_H_

#include <glib.h>

struct meow_server {
  char* address;
  int port;
  GHashTable* memory_store;
};

typedef struct meow_server MeowServer;

MeowServer* init_server(char* address, int port);

int start_server(MeowServer* server, void (*handler)(MeowServer*, char*, char*));

#endif // SERVER_H_
