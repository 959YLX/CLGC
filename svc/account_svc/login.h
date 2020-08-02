#ifndef __CLGC_SVC_ACCOUNT_LOGIN__
#define __CLGC_SVC_ACCOUNT_LOGIN__

#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpServer.h>
#include <muduo/base/Timestamp.h>

#include <string>

#endif

class CLGCLoginServer {
    public:
        CLGCLoginServer(muduo::net::EventLoop* loop, const muduo::net::InetAddress& addr);
        void start();

        const std::string login_server_name = "CLGC_Login_server";
    private:
        void onConnection(const muduo::net::TcpConnectionPtr& conn);
        void onMessage(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, muduo::Timestamp ts);

        muduo::net::EventLoop* _login_loop;
        muduo::net::TcpServer _login_server;
};