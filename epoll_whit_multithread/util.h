#ifndef HEADER_UTIL
#define HEADER_UTIL

#include <string>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>

int SetSocketNoblocking(uint64_t sock) {
    int old_option = fcntl(sock, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(sock, F_SETFL, new_option);
    return old_option;
}

int SetReusePort(uint64_t sock) {
    int opt = 1;
    int ret = setsockopt(sock, SOL_SOCKET, SO_REUSEPORT,
        &opt, static_cast<socklen_t>(sizeof(opt)));
    return ret;
}

bool Bind(uint64_t sock, uint16_t port, const std::string& ip) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = ip.empty() ? INADDR_ANY : inet_addr(ip.c_str());

    int ret = bind(sock, (sockaddr *)&addr, sizeof(sockaddr));

    if (ret < 0) {
        std::cout << "linux bind socket filed! error code:" << errno << std::endl;
        close(sock);
        return false;
    }
    return true;
}

bool Listen(uint64_t sock) {
    int ret = listen(sock, SOMAXCONN);
    if (ret < 0) {
        std::cout << "linux listen socket filed! error code:" << errno << std::endl;
        close(sock);
        return false;
    }
    return true;
}

#endif