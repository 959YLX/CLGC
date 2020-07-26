#ifndef __CLGC_SVC_MAIN__
#define __CLGC_SVC_MAIN__

#include <iostream>
#include <time.h>

#include "pb/cs_common.pb.h"
#include "pb/gclogin.pb.h"

#endif

int main(int argc, char const *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    csproto::ServerResponse rsp;
    rsp.set_code(0);
    rsp.set_msg("success");
    csproto::LoginResponse login_response;
    login_response.set_success(true);
    time_t now;
    time(&now);
    login_response.set_now(now);
    login_response.set_session("m test session");
    auto success_data = new google::protobuf::Any();
    success_data->PackFrom(login_response);
    rsp.set_allocated_success_data(success_data);
    auto rsp_data = rsp.SerializeAsString();
    auto pt_data = rsp.DebugString();
    std::cout << "success marshal pb data, debug string is " << pt_data << std::endl;
    return 0;
}
