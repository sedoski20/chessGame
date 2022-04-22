set(BINARY ${PROJECT_NAME}_client)

set(SRCS
    main.cpp
    boardmodel.cpp
    squaremodel.cpp
    serverinterface.cpp
)
qt5_add_resources(RESOURCES ../qml.qrc)

add_executable(${BINARY} ${SRCS} ${RESOURCES})
target_include_directories(${BINARY} PUBLIC ${PROJECT_SOURCE_DIR}/client/src)
target_include_directories(${BINARY} PUBLIC ${PROJECT_SOURCE_DIR}/game/src)
target_include_directories(${BINARY} PUBLIC ${PROJECT_SOURCE_DIR}/grpc)    
target_link_libraries(${BINARY} PUBLIC
    interface
    ChessGame_lib 
    Qt5::Core
    Qt5::Qml
    Qt5::Quick
    Qt5::Widgets    
)
    
set_target_properties( ${BINARY}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/client"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/client"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/client"
)