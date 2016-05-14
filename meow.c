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
  if(strncmp("GET", message, 3) == 0) {
    sprintf(response, "No such key. Meow!");
  } else if(strncmp("PUT", message, 3) == 0) {
    sprintf(response, "Ok. Meow!");
  } else if(strncmp("DELETE", message, 6) == 0) {
    sprintf(response, "Deleted. Meow!");
  } else if(strncmp("EXISTS?", message, 7) == 0) {
    sprintf(response, "No. Meow!");
  }
}

int main(int argc, char *argv[])
{
  return meow_server((char*)ADDRESS, PORT, handle_incoming_message);
}
