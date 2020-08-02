#ifndef __CLGC_PB_TOOLS__
#define __CLGC_PB_TOOLS__

#include "cs_common.pb.h"
#include "gclogin.pb.h"

#include <string>

#define __CLGC_SVC_VERSION__ 1

#endif

bool unmarshal(const std::string& msg, google::protobuf::Message *real_msg);
std::shared_ptr<std::string> build_error_msg(int code, std::string& msg, google::protobuf::Message* error_data);