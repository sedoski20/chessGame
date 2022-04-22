cmake_minimum_required(VERSION 3.20.0)
project(ChessGame)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(game)
add_subdirectory(server)
add_subdirectory(client)

enable_testing()

