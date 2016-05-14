#ifndef SERVER_H_   /* Include guard */
#define SERVER_H_

int meow_server(char* address, int port, void (*handler)(char*, char*));

#endif // SERVER_H_
