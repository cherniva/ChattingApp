//
// Created by Ivan Chernikov on 12.02.2024.
//

#ifndef GROUPCHAT_SERVER_H
#define GROUPCHAT_SERVER_H

void initialize_server(int port);

void start_listening();

void accept_client_connection();

void handle_client_messages(int client_socket);

void broadcast_message(int sender_socket, const char *message);

void disconnect_client(int client_socket);

void handle_client_commands(int client_socket, const char *command);

void shutdown_server();

#endif //GROUPCHAT_SERVER_H
