add_executable(Server main.cpp server.cpp)

target_include_directories(Server PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(Server PRIVATE ${Boost_LIBRARIES})
