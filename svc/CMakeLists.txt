cmake_minimum_required(VERSION 3.6)

project(clgc_svc)

find_path(Muduo_INCLUDE_DIR muduo)
find_path(Muduo_LIBRARY_DIR libmuduo_net.a)

include_directories(${Muduo_INCLUDE_DIR})
find_library(muduo_base muduo_base)
find_library(muduo_net muduo_net)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
aux_source_directory(. SVC_SRCS)

add_subdirectory(pb)
add_subdirectory(account_svc)
add_executable(svc_main main.cpp)

target_link_libraries(svc_main svc_pb account_svc)
target_link_libraries(svc_main ${muduo_net})
target_link_libraries(svc_main ${muduo_base})
target_link_libraries(svc_main pthread rt)