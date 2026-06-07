cmake_minimum_required(VERSION 3.10)
project(asio_server)

add_executable(server src/server.cpp src/main.cpp)

target_link_libraries(server boost::asio::static)
