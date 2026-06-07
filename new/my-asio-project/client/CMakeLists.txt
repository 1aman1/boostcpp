add_executable(Client main.cpp client.cpp)

target_include_directories(Client PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(Client PRIVATE ${Boost_LIBRARIES})
