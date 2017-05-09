//
// Created by mbataglia on 01/05/17.
//

#ifndef TP3_COMMONPROTOCOL_H
#define TP3_COMMONPROTOCOL_H


#include "commonSocket.h"
#include <string>
#include <vector>

class Protocol {
public:
    int sendString(Socket *skt,const char *msg);

    int send_int(Socket *skt, int32_t integer);

    int recvString(Socket *skt, char *buffer);

    int recv_int(Socket *skt, int32_t *integer);

    void iniciarCliente(Socket *skt, int argc, char **argv);

    std::string formatCommand(std::string line);

    std::vector<std::string> split(const std::string &s, char delim);
};


#endif //TP3_COMMONPROTOCOL_H
