//
// Created by mbataglia on 01/05/17.
//

#define _POSIX_C_SOURCE 200112L
#include "commonSocket.h"
//todo
//quitar operador de copia como en threads
Socket::Socket() {
    fd = socket(AF_INET, SOCK_STREAM, 0);
}

Socket::Socket(int fd) {
    this->fd = fd;
}

Socket::~Socket() {
    if (fd != -1){
        close(fd);
    }
}

int Socket::connectS(char *ip, int puerto) {
    struct addrinfo hints;
    struct addrinfo *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;

    char puertoStr[6]; //cant max de caracteres para un puerto
    snprintf(puertoStr,sizeof(puertoStr), "%d", puerto);
    int returnCode = getaddrinfo(ip, puertoStr, &hints, &result);

    if (returnCode != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(returnCode));
        freeaddrinfo(result);
        exit(EXIT_FAILURE);
    }

    int connectResult = connect(fd, result->ai_addr,
                                result->ai_addrlen);

    freeaddrinfo(result);
    return connectResult;
}

int Socket::bindS(int puerto) {
    struct sockaddr_in direccionLocal;
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = inet_addr(IP_LOCAL);
    direccionLocal.sin_port = htons(puerto);
    return bind(fd, (struct sockaddr *)&direccionLocal,
                sizeof(direccionLocal));
}

int Socket::listenS(int cantidad) {
    return listen(fd, cantidad);
}

Socket *Socket::acceptS() {
    struct sockaddr_in con_addr;
    socklen_t struct_size = sizeof(con_addr);
    int clientFd = accept(fd, (struct sockaddr*)&con_addr,
                                &struct_size);
    return new Socket(clientFd); //todo hacer delete
}

int Socket::recvS(void *buffer, int toRead) {
    int flags = MSG_NOSIGNAL;
    size_t toread = toRead;
    char  *bufptr = (char*) buffer;
    while (toread > 0){
        ssize_t leido = recv(fd,bufptr,toread,flags);
        if (leido <= 0)
            return leido;
        toread -= leido;
        bufptr += leido;
    }
    return OK_SOCKET;
}

int Socket::sendS(const void *msg, int toSend) {
    int flags = MSG_NOSIGNAL;
    char *ptr = (char*) msg;
    while (toSend > 0){
        int bytes = send(fd, ptr, toSend,flags);
        if (bytes < 1){
            return ERROR;
        }
        ptr += bytes;
        toSend -= bytes;
    }
    return OK_SOCKET;
}

int Socket::shutdownWriteS() {
    return shutdown(fd,SHUT_WR);
}

int Socket::shutdownS() {
    return shutdown(fd,SHUT_RDWR);
}


