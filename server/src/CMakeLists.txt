set(BINARY ${PROJECT_NAME}_server)

add_executable(${BINARY} main.cpp)

include_directories( ${PROJECT_SOURCE_DIR}/game/src)
target_link_libraries(${BINARY} PUBLIC ChessGame_lib)

set_target_properties( ${BINARY}
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/server"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/server"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/server"
)


