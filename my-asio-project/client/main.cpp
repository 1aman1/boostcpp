#include "client.h"
#include <iostream>

int main() {
    const std::string host = "localhost";
    const int port = 8080;

    Client client(host, port);
    client.run();

    return 0;
}
