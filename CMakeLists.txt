cmake_minimum_required(VERSION 2.8)
project(ChessGame)

set(CMAKE_PREFIX_PATH /home/sedoski/Qt/5.15.2/gcc_64)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(
    Qt5 REQUIRED
    Core
    Qml
    Quick
    Widgets
    )
    
add_subdirectory(src)
add_subdirectory(lib/game)


