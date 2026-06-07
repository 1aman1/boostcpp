#include "server.h"

Server::Server() : acceptor(io_context, tcp::endpoint(tcp::v4(), 8080)), socket(io_context) {
    start_accept();
}

void Server::run() {
    io_context.run();
}

void Server::start_accept() {
    acceptor.async_accept(socket, [this](const boost::system::error_code& error) {
        handle_accept(error);
    });
}

void Server::handle_accept(const boost::system::error_code& error) {
    if (!error) {
        std::cout << "Client connected!" << std::endl;

        boost::asio::async_read(socket, boost::asio::buffer(data, max_length),
                                [this](const boost::system::error_code& error, size_t bytes_transferred) {
                                    handle_read(error, bytes_transferred);
                                });
    } else {
        std::cerr << "Accept error: " << error.message() << std::endl;
    }
}

void Server::handle_read(const boost::system::error_code& error, size_t bytes_transferred) {
    if (!error) {
        std::cout << "Message received from client: " << data << std::endl;

        boost::asio::async_write(socket, boost::asio::buffer(data, bytes_transferred),
                                 [this](const boost::system::error_code& error, size_t /*bytes_transferred*/) {
                                     handle_write(error);
                                 });

        start_accept();
    } else {
        std::cerr << "Read error: " << error.message() << std::endl;
        socket.close();
        start_accept();
    }
}

void Server::handle_write(const boost::system::error_code& error) {
    if (!error) {
        std::cout << "Message sent to client successfully!" << std::endl;
    } else {
        std::cerr << "Write error: " << error.message() << std::endl;
        socket.close();
    }
}
