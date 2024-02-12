//
// Created by Ivan Chernikov on 12.02.2024.
//

#include "server.h"

int initialize_server(int port) {
    struct sockaddr_in addr = {.sin_family=AF_INET, .sin_port=htonl(port), .sin_addr.s_addr=htonl(INADDR_ANY)};
    int socketfd = socket(AF_INET, SOCK_STREAM, 0); // SOCK_STREAM (for TCP) or SOCK_DGRAM (for UDP) //TODO: check value
    bind(socketfd, (struct sockaddr*)&addr, sizeof(addr)); //TODO: check return

    return socketfd;
}

void start_listening(int server_socket) {
    listen(server_socket, 5); //TODO: check return
}

int accept_client_connection(int server_socket) {
    struct sockaddr_in client_addr;
    int len = sizeof(client_addr);
    int connectedfd = accept(server_socket, (struct sockaddr*)&client_addr, &len);

    return connectedfd;
}

char* handle_client_messages(int client_socket, int buffer_size) {
    char* buff = calloc(buffer_size, sizeof(char));

    read(client_socket, buff, sizeof(buff));

    return buff;
}

void disconnect_client(int client_socket) {
    close(client_socket);
}

void shutdown_server(int server_socket) {
//    shutdown(server_socket, SHUT_RDWR);
    close(server_socket);
}