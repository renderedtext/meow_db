#ifndef SERVER_H_   /* Include guard */
#define SERVER_H_

#include <glib.h>

struct zen_server {
  char* address;
  int port;
  GHashTable* memory_store;
};

typedef struct zen_server ZenServer;

ZenServer* init_server(char* address, int port);

int start_server(ZenServer* server, void (*handler)(ZenServer*, char*, char*));

#endif // SERVER_H_
