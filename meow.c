#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

const char* ADDRESS = "0.0.0.0";
const int PORT = 6666;

void handle_incoming_message(char* response, char* message) {
  sprintf(response, "%s meow!", message);
}

int run_server() {
    int socket_desc;
    int new_socket;
    int c;
    struct sockaddr_in server;
    struct sockaddr_in client;

    char *incoming_message;
    int message_length;

    char message_buffer[2000];
    char response_buffer[2000];


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

        message_length = recv(new_socket, message_buffer, 2000, 0);

        if(message_length < 0) {
          puts("Failed to receive message");
        } else {
          incoming_message = (char*)malloc(message_length + 1);

          memcpy(incoming_message, message_buffer, message_length + 1);
          incoming_message[message_length] = '\0';

          printf("Message received: %s\n", incoming_message);

          //Reply to the client
          handle_incoming_message(response_buffer, incoming_message);
          write(new_socket, response_buffer, strlen(response_buffer));

          printf("Response message: %s\n", response_buffer);

          free(incoming_message);
        }
    }

    if(new_socket < 0)
    {
        perror("Accept failed");
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
  return run_server();
}
