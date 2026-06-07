#include <boost/asio.hpp>
#include <iostream>

class Client {
public:
    explicit Client(const std::string& host, int port);

    void run();

private:
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::resolver resolver;
    boost::asio::ip::tcp::socket socket;
};
