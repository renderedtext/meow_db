#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

const char* ADDRESS = "0.0.0.0";
const int PORT = 6666;

int main(int argc, char *argv[])
{
    int socket_desc;
    int new_socket;
    int c;
    struct sockaddr_in server;
    struct sockaddr_in client;
    char *response_message;
    char incomming_message[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket meow://%s:%d", ADDRESS, PORT);
        return 1;
    }

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Could not bind to meow://%s:%d", ADDRESS, PORT);
        return 1;
    }

    // Listen
    listen(socket_desc, 3);

    printf("Server is listening on meow://%s:%d\n", ADDRESS, PORT);

    // Accept and incoming connection
    puts("Waiting for incoming connections...");

    c = sizeof(struct sockaddr_in);
    while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        printf("\n");
        puts("Connection accepted");

        if(recv(new_socket, incomming_message, 2000, 0) < 0) {
          puts("Failed to receive message");
        } else {
          printf("Message received: %s\n", incomming_message);

          //Reply to the client
          response_message = (char *)("meow!");
          write(new_socket, response_message, strlen(response_message));

          printf("Response message: %s\n", response_message);
        }
    }

    if(new_socket < 0)
    {
        perror("Accept failed");
        return 1;
    }

    return 0;
}
