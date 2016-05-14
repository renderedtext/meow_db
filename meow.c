#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#include "server.h"

const char* ADDRESS = "0.0.0.0";
const int PORT = 6666;

void handle_incoming_message(char* response, char* message) {
  sprintf(response, "%s meow!", message);
}

int main(int argc, char *argv[])
{
  return meow_server((char*)ADDRESS, PORT, handle_incoming_message);
}
