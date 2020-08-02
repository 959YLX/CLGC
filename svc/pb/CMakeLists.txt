include(FindProtobuf)
find_package(Protobuf REQUIRED)

aux_source_directory(. PB_LIB_SRCS)
add_library(svc_pb ${PB_LIB_SRCS})

target_link_libraries(svc_pb ${PROTOBUF_LIBRARIES})