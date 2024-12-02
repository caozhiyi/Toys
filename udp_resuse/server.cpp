#include <iostream>
#include <thread>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

const int BUFFER_SIZE = 1024;
const int PORT = 8080; // 监听端口
const char* TARGET_IP = "127.0.0.1"; // 转发目标IP
const int TARGET_PORT = 9090; // 转发目标端口

void handle_client() {
    // 创建UDP套接字
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return;
    }

    // 设置SO_REUSEPORT选项
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        std::cerr << "Error setting SO_REUSEPORT" << std::endl;
        close(sockfd);
    }

    // 绑定套接字到端口
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // 监听所有可用的IP地址
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error binding socket:" << sockfd << std::endl;
        close(sockfd);
        return;
    }

    std::cout << "Listening on socket:" << sockfd << "port " << PORT << std::endl;

    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    while (true) {
        // 接收数据
        ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &addr_len);
        if (n < 0) {
            std::cerr << "Error receiving data socket:" << sockfd << std::endl;
            continue;
        }

        // 打印接收到的数据
        buffer[n] = '\0'; // 确保字符串以null结尾
        std::cout << "socket:" << sockfd<< " Received " << n << " bytes from " << inet_ntoa(client_addr.sin_addr) << ": " << buffer << std::endl;
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 2; ++i) {
        threads.emplace_back(handle_client);
    }

    // 等待所有线程完成
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}