#include <boost/asio.hpp>
#include <iostream>

class Server {
public:
    explicit Server(int port);

    void run();

private:
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::acceptor acceptor;
};
