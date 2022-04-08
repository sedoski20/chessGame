project(ChessGame)

set(SRCS
    main.cpp
    boardmodel.cpp
    squaremodel.cpp
)
set(BINARY ${PROJECT_NAME})

qt5_add_resources(RESOURCES ../qml.qrc)
add_executable(${BINARY} ${SRCS} ${RESOURCES})

set_target_properties( ${BINARY}
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

include_directories(
    ${PROJECT_SOURCE_DIR}/game/src
    ${PROJECT_SOURCE_DIR}/qt/src
)

target_link_libraries(${BINARY} PUBLIC
    ChessGame_lib 
    Qt5::Core
    Qt5::Qml
    Qt5::Quick
    Qt5::Widgets    
)

