# Builds the two code generators the Hadoop maven build would otherwise
# download as prebuilt Linux/macOS/Windows binaries:
#   protoc                 -- from protobuf ${PROTOBUF_SRC}
#   protoc-gen-grpc-java   -- from grpc-java ${GRPC_JAVA_SRC}, linked against
#                             the same libprotoc
cmake_minimum_required(VERSION 3.16)
project(hadoop-protoc-tools LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(protobuf_ABSL_PROVIDER package CACHE STRING "")
set(protobuf_BUILD_TESTS OFF CACHE BOOL "")
set(protobuf_BUILD_SHARED_LIBS OFF CACHE BOOL "")
set(protobuf_BUILD_LIBUPB OFF CACHE BOOL "")
set(protobuf_INSTALL OFF CACHE BOOL "")
set(protobuf_WITH_ZLIB OFF CACHE BOOL "")
add_subdirectory(${PROTOBUF_SRC} protobuf EXCLUDE_FROM_ALL)

add_executable(protoc-gen-grpc-java
  ${GRPC_JAVA_SRC}/compiler/src/java_plugin/cpp/java_generator.cpp
  ${GRPC_JAVA_SRC}/compiler/src/java_plugin/cpp/java_plugin.cpp)
target_link_libraries(protoc-gen-grpc-java PRIVATE protobuf::libprotoc protobuf::libprotobuf)
