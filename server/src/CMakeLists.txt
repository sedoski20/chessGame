set(BINARY ${PROJECT_NAME}_server)

add_executable(${BINARY} main.cpp request.cpp)
target_include_directories(${BINARY} PUBLIC ${PROJECT_SOURCE_DIR}/server/src)
target_include_directories(${BINARY} PUBLIC ${PROJECT_SOURCE_DIR}/game/src)
target_include_directories(${BINARY} PUBLIC ${PROJECT_SOURCE_DIR}/grpc)

target_link_libraries(${BINARY} 
    interface 
    ChessGame_lib
)

set_target_properties( ${BINARY}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/server"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/server"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/server"
)
