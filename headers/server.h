#ifndef SERVER_H_   /* Include guard */
#define SERVER_H_

struct meow_server {
  char* address;
  int port;
};

typedef struct meow_server MeowServer;

int start_server(MeowServer* server, void (*handler)(MeowServer*, char*, char*));

#endif // SERVER_H_
