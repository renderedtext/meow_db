#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

const char* ADDRESS = "0.0.0.0";
const int PORT = 6666;

int main(int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char server_reply[2000];
    int message_length;
    char message[2000];
    int result;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr(ADDRESS);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        printf("Connect error: Could not connect to zen://%s:%d\n", ADDRESS, PORT);
        return 1;
    }

    while(1) {
      printf("zen[%s:%d] >>> ", ADDRESS, PORT);

      fgets(message, sizeof(message), stdin);

      result = send(socket_desc, message, strlen(message), 0);

      if(result < 0)
      {
          puts("Send failed");
          return 1;
      }

      // Receive a reply from the server
      message_length = recv(socket_desc, server_reply, 2000, 0);
      if(message_length < 0)
      {
          puts("recv failed");
          return 1;
      }

      puts(server_reply);
    }

    return 0;
}
