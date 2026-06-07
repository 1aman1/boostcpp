#include "server.h"
#include <iostream>

int main() {
    const int port = 8080;

    Server server(port);
    server.run();

    return 0;
}
