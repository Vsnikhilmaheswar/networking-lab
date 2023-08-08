#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Set up server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(8080);

    // Connect
    connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    // Send and receive messages
    while (1) {
        printf("Client: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(clientSocket, buffer, strlen(buffer), 0);

        recv(clientSocket, buffer, sizeof(buffer), 0);
        printf("Server: %s\n", buffer);
    }

    close(clientSocket);

    return 0;
}
