#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Client {
public:
    Client();

    void run();

private:
    boost::asio::io_context io_context;
    tcp::socket socket;
    enum { max_length = 1024 };
    char data[max_length];

    void handle_read(const boost::system::error_code& error, size_t bytes_transferred);
    void handle_write(const boost::system::error_code& error);
    void handle_close(const boost::system::error_code& error);

};

#endif // CLIENT_H
