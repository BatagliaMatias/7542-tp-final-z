//
// Created by mbataglia on 01/05/17.
//

#include "commonProtocol.h"
#include "commonSocket.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#define OK_PROTOCOL 1

int Protocol::recv_int(Socket *skt, int32_t* integer){
    int32_t hostInteger = 0;
    skt->recvS(&hostInteger,sizeof(int32_t));
    *integer = ntohl(hostInteger);
    return OK_PROTOCOL;
}

int Protocol::recvString(Socket *skt,char* buffer){
    int size = 0;
    recv_int(skt,&size);
    skt->recvS(buffer,size);
    return size;
}

int Protocol::send_int(Socket *skt,int32_t integer){
    int32_t networkInteger = htonl(integer);
    return skt->sendS(&networkInteger,sizeof(int32_t));
}

int Protocol::sendString(Socket *skt,const char* msg){
    int n = strlen(msg);
    send_int(skt,n);
    int longitud = strlen(msg);
    return skt->sendS(msg,longitud);
}

std::vector<std::string> Protocol::split(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(std::move(item));
    }
    return elems;
}
