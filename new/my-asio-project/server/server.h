#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Server {
public:
    Server();

    void run();

private:
    boost::asio::io_context io_context;
    tcp::acceptor acceptor;
    tcp::socket socket;
    enum { max_length = 1024 };
    char data[max_length];

    void start_accept();
    void handle_accept(const boost::system::error_code& error);
    void handle_read(const boost::system::error_code& error, size_t bytes_transferred);
    void handle_write(const boost::system::error_code& error);
};

#endif // SERVER_H
