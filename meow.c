#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#include "server.h"
#include "api.h"

void router(MeowServer* server, char* message, char* response) {
  int result;

  if(strncmp("GET", message, 3) == 0)
  {
    result = meow_get(server, (char*)"test_key", response);
  }
  else if(strncmp("PUT", message, 3) == 0)
  {
    result = meow_put(server, (char*)"test_key", (char*)"test_value", response);
  }
  else if(strncmp("DELETE", message, 6) == 0)
  {
    result = meow_delete(server, (char*)"test_key", response);
  }
  else if(strncmp("EXISTS?", message, 7) == 0)
  {
    result = meow_exists(server, (char*)"test_key", response);
  }

  if(result < 0) {
    sprintf(response, "Fail");
  }
}

const char* ADDRESS = "0.0.0.0";
const int PORT = 6666;

int main(int argc, char *argv[])
{
  MeowServer server;

  server.address = (char*)ADDRESS;
  server.port = PORT;

  return start_server(&server, router);
}
