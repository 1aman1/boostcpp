#include "server.h"
#include <boost/asio/accept.hpp>

Server::Server(int port) : acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
}

void Server::run() {
    while (true) {
        boost::asio::ip::tcp::socket socket(io_service);
        acceptor.accept(socket);

        std::string message = "Hello from the server!";
        boost::asio::write(socket, boost::asio::buffer(message), boost::asio::use_any_executor);

        socket.close();
    }
}
