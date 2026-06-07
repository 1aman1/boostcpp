cmake_minimum_required(VERSION 3.10)
project(asio_client_server)

add_subdirectory(client)
add_subdirectory(server)

target_link_libraries(client boost::asio)
target_link_libraries(server boost::asio)
