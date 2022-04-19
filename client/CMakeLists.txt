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





