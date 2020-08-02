#include "tools.h"

bool unmarshal(const std::string& msg, google::protobuf::Message *real_msg) {
    if (real_msg == nullptr) {
        return false;
    }
    auto req = csproto::ClientRequest{};
    if (!req.ParseFromString(msg)) {
        return false;
    }
    if (req.client_version() > __CLGC_SVC_VERSION__) {
        // 版本不匹配
        return false;
    }
    if (req.msg().GetTypeName() != real_msg->GetTypeName()) {
        return false;
    }
    return req.msg().UnpackTo(real_msg);
}

std::shared_ptr<std::string> build_error_msg(int code, std::string& msg, google::protobuf::Message* error_data) {
    csproto::ServerResponse rsp;
    rsp.set_code(code);
    rsp.set_msg(msg);
    auto rsp_msg = std::shared_ptr<std::string>(new std::string());
    rsp.SerializeToString(rsp_msg.get());
    return rsp_msg;
}