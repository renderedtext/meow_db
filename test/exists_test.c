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
    char *message;
    char server_reply[2000];
    int message_length;

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

    puts("Connected\n");

    // Send some data
    message = (char *)("EXISTS? zen_key");
    if(send(socket_desc, message, strlen(message), 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Data Send\n");

    // Receive a reply from the server
    message_length = recv(socket_desc, server_reply, 2000, 0);
    if(message_length < 0)
    {
        puts("recv failed");
        return 1;
    }

    puts("Reply received\n");
    puts(server_reply);

    if(strncmp(server_reply, "Fail", message_length) == 0) {
      return 0;
    } else {
      return 1;
    }
}
