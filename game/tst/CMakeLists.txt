set(BINARY ${PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})
set(GTEST ${PROJECT_SOURCE_DIR}/game/lib/googletest/)
set(GAME ${PROJECT_SOURCE_DIR}/game/src)

add_executable(${BINARY} ${SOURCES})

target_include_directories(${BINARY} PUBLIC ${GAME})
target_include_directories(${BINARY} PUBLIC ${GTEST}/googlemock/include)
target_include_directories(${BINARY} PUBLIC ${GTEST}/googletest/include)
include(GoogleTest)

add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC ChessGame_lib gtest gmock)

set_target_properties( ${BINARY}
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/game"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/game"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/game"
)