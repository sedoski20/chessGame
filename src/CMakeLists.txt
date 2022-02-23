set(SRCS
    main.cpp
    boardmodel.cpp
    squaremodel.cpp
)


qt5_add_resources(RESOURCES ../qml.qrc)
add_executable(ChessGame_qt ${SRCS} ${RESOURCES})

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/lib/game/src
)

target_link_libraries(ChessGame_qt PUBLIC
    game 
    Qt5::Core
    Qt5::Qml
    Qt5::Quick
    Qt5::Widgets    
)

