#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#include "server.h"
#include "api.h"

void router(ZenServer* server, char* message, char* response) {
  int result;

  const char* separator = " ";

  char* action;
  char* key;
  char* value;

  action = strtok(message, separator);
  key    = strtok(NULL, separator);
  value  = strtok(NULL, separator);

  if(action == NULL) {
    sprintf(response, "Invalid");

    return;
  }

  printf("action: %s, key: %s\n", action, key);

  if(strcmp(action, "GET") == 0)
  {
    result = zen_get(server, g_strstrip(key), response);
  }
  else if(strcmp(action, "PUT") == 0)
  {
    printf("value: %s\n", value);

    result = zen_put(server, g_strstrip(key), g_strstrip(value), response);

    if(result == TRUE) {
      sprintf(response, "Ok");
    }
  }
  else if(strcmp(action, "DELETE") == 0)
  {
    result = zen_delete(server, g_strstrip(key), response);

    if(result == TRUE) {
      sprintf(response, "Ok");
    }
  }
  else if(strcmp(action, "EXISTS") == 0)
  {
    result = zen_exists(server, g_strstrip(key), response);

    if(result == TRUE) {
      sprintf(response, "Ok");
    }
  }

  if(result == FALSE) {
    sprintf(response, "Fail");
  }
}

const char* ADDRESS = "0.0.0.0";
const int PORT = 6666;

int main(int argc, char *argv[])
{
  ZenServer* server = init_server((char*)ADDRESS, PORT);

  return start_server(server, router);
}
