set(BINARY game)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

# add_executable(${BINARY} ${SOURCES})

add_library(${BINARY} STATIC ${SOURCES})