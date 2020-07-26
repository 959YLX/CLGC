cmake_minimum_required(VERSION 3.6)

project(clgc_svc)

include(FindProtobuf)
find_package(Protobuf REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
aux_source_directory(. SVC_SRCS)

add_subdirectory(pb)
add_executable(svc_main main.cpp)

target_link_libraries(svc_main svc_pb ${PROTOBUF_LIBRARIES})