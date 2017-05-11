//
// Created by mbataglia on 01/05/17.
//

#ifndef TP3_COMMONSOCKET_H
#define TP3_COMMONSOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>


#define BUFFER_SIZE 100
#define BYTES_TAMANIO 4
#define OK_SOCKET 1
#define ERROR 0

#define LISTEN_TO '5'
#define IS_CHECKSUM '1'
#define IS_NEW_DATA '3'
#define IS_EQUAL_BLOCK '4'
#define IS_SERVER_EOF '5'
#define END_OF_CHECKSUM '2'
#define IP_LOCAL "127.0.0.1"

class Socket {
private:
    int fd;

public:
    Socket();

    explicit Socket(int fd);

    virtual ~Socket();

    int connectS(char* ip,int puerto);

    int bindS(int puerto);

    int listenS(int cantidad);

    Socket* acceptS();

    int recvS(void* buffer, int toRead);

    int sendS(const void* msg,int toSend);

    int shutdownS();

    int shutdownWriteS();
};


#endif //TP3_COMMONSOCKET_H
