cmake_minimum_required(VERSION 3.10)
project(asio_client)

add_executable(client src/client.cpp src/main.cpp)

target_link_libraries(client boost::asio::static)
