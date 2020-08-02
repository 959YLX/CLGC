aux_source_directory(. ACCOUNT_SVC_SRCS)

add_library(account_svc ${ACCOUNT_SVC_SRCS})
target_link_libraries(account_svc svc_pb)