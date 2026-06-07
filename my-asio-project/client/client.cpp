#include "client.h"
#include <boost/asio/connect.hpp>

Client::Client(const std::string& host, int port) : resolver(io_service), socket(io_service) {
    boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), host, std::to_string(port));
    boost::asio::connect(socket, resolver.resolve(query));
}

void Client::run() {
    try {
        std::string message;
        boost::asio::read(socket, boost::asio::buffer(message), boost::asio::use_any_executor);

        std::cout << "Received message: " << message << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
