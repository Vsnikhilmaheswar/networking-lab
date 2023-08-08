#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int serverSocket, clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientLen = sizeof(clientAddr);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Set up server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);

    // Bind
    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    // Listen
    listen(serverSocket, 5);

    printf("Server is listening...\n");

    // Accept connection
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientLen);
    printf("Connected to client\n");

    // Receive and send messages
    while (1) {
        recv(clientSocket, buffer, sizeof(buffer), 0);
        printf("Client: %s\n", buffer);

        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(clientSocket, buffer, strlen(buffer), 0);
    }

    close(clientSocket);
    close(serverSocket);

    return 0;
}
