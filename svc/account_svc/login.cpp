#include "login.h"
#include "../pb/tools.h"
#include "../pb/gclogin.pb.h"

#include <functional>

CLGCLoginServer::CLGCLoginServer(muduo::net::EventLoop* loop, const muduo::net::InetAddress& addr) : 
_login_loop(loop), _login_server(loop, addr, login_server_name)
{
    _login_server.setConnectionCallback(std::bind(&CLGCLoginServer::onConnection, this, std::placeholders::_1));
    _login_server.setMessageCallback(std::bind(&CLGCLoginServer::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void CLGCLoginServer::start() {
    _login_server.start();
}

void CLGCLoginServer::onConnection(const muduo::net::TcpConnectionPtr& conn) {

}
void CLGCLoginServer::onMessage(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, muduo::Timestamp ts) {
    const auto msg = std::string(buf->retrieveAllAsString());
    csproto::LoginRequest login_req;
    if (!unmarshal(msg, &login_req)) {
        auto err_msg = std::string("error to unmarshal login msg");
        auto rsp_msg = build_error_msg(1, err_msg, nullptr);
        conn->send(*rsp_msg.get());
        return;
    }
    std::cout << "receive login msg: " << login_req.DebugString() << std::endl;
    auto succ_msg = std::string("success");
    auto rsp_msg = build_error_msg(0, succ_msg, nullptr);
    conn->send(*rsp_msg.get());
    return;
}