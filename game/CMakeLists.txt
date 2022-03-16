cmake_minimum_required(VERSION 3.0)
project(ChessGame_lib)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

# add_subdirectory(temp)
