#include "client.h"

Client::Client() : socket(io_context) {}

void Client::run() {
    try {
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("127.0.0.1", "8080");

        boost::asio::connect(socket, endpoints);

        std::cout << "Enter message: ";
        std::cin.getline(data, max_length);

        boost::asio::async_write(socket, boost::asio::buffer(data, std::strlen(data)),
                                 [this](const boost::system::error_code& error, size_t /*bytes_transferred*/) {
                                     handle_write(error);
                                 });

        io_context.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Client::handle_write(const boost::system::error_code& error) {
    if (!error) {
        std::cout << "Message sent to the server successfully!" << std::endl;

        // Note: Do not close the socket here; wait for the server response.
    } else {
        std::cerr << "Write error: " << error.message() << std::endl;
        socket.close();
        io_context.stop();
    }
}

void Client::handle_close(const boost::system::error_code& error) {
    if (!error) {
        std::cout << "Connection closed by the server." << std::endl;
    } else {
        std::cerr << "Close error: " << error.message() << std::endl;
    }

    socket.close();
    io_context.stop();
}


void Client::handle_read(const boost::system::error_code& error, size_t bytes_transferred) {
    if (!error) {
        std::cout << "Message received from the server: " << data << std::endl;

        // Call handle_close to close the connection after receiving the response.
        handle_close(error);
    } else {
        std::cerr << "Read error: " << error.message() << std::endl;
        socket.close();
        io_context.stop();
    }
}

