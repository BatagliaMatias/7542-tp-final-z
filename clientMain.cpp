#include <iostream>
#include "commonSocket.h"

int main(int argc, char *argv[]) {
    std::cout << "client" << std::endl;
    Socket socket;
    socket.connectS(argv[1],16332);
    socket.sendS(argv[2],5);
    socket.shutdownS();
    return 0;
}
