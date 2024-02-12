//
// Created by Ivan Chernikov on 12.02.2024.
//

#ifndef GROUPCHAT_SERVER_H
#define GROUPCHAT_SERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

int initialize_server(int port);

void start_listening(int server_socket);

int accept_client_connection(int server_socket);

char* handle_client_messages(int client_socket, int buffer_size);

//void broadcast_message(int sender_socket, const char *message);

void disconnect_client(int client_socket);

//void handle_client_commands(int client_socket, const char *command);

void shutdown_server(int server_socket);

#endif //GROUPCHAT_SERVER_H
