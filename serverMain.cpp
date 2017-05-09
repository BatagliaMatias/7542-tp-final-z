#include <iostream>
#include "commonSocket.h"
int main(int argc, char *argv[]) {
    std::cout << "server" << std::endl;
    Socket socket;
    socket.bindS(16332);
    socket.listenS(5);
    Socket* cliente  = socket.acceptS();
    char buffer[10];
    cliente->recvS(buffer,10);
    cliente->shutdownS();
    socket.shutdownS();
    std::cout << buffer << std::endl;
    return 0;
}
