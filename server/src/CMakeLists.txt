set(BINARY ${PROJECT_NAME}_server)


# This configuration assumes that gRPC and all its dependencies are already installed
# on this system, so they can be located by find_package().

# Find Protobuf installation
# Looks for protobuf-config.cmake file installed by Protobuf's cmake installation.
set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)

# Find gRPC installation
# Looks for gRPCConfig.cmake file installed by gRPC's cmake installation.
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

set(_GRPC_GRPCPP gRPC::grpc++)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)


# # hw_grpc_proto
add_library(interface
../../grpc/interface.grpc.pb.cc
../../grpc/interface.grpc.pb.h
../../grpc/interface.pb.cc
../../grpc/interface.pb.h)

target_include_directories(interface PUBLIC ../../grpc)
target_link_libraries(interface 
${_REFLECTION}
${_GRPC_GRPCPP}
${_PROTOBUF_LIBPROTOBUF})

add_executable(${BINARY} main.cpp request.cpp)
target_include_directories(${BINARY} PUBLIC ${PROJECT_SOURCE_DIR}/game/src)
target_include_directories(${BINARY} PUBLIC ../../grpc)
target_link_libraries(${BINARY} 
interface 
ChessGame_lib
${_REFLECTION}
${_GRPC_GRPCPP}
${_PROTOBUF_LIBPROTOBUF})

set_target_properties( ${BINARY}
PROPERTIES
ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/server"
LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/server"
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/server"
)
