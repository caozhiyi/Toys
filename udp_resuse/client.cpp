#include <iostream>
#include <thread>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

const char* TARGET_IP = "127.0.0.1"; // 转发目标IP
const int TARGET_PORT = 8080; // 转发目标端口

void handle_client(int index) {
    // 创建UDP套接字
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return;
    }

    char buffer[1024] = {0};
    sprintf(buffer, "%d Hello, UDP server!", index);

    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(TARGET_PORT);
    inet_pton(AF_INET, TARGET_IP, &target_addr.sin_addr);

    while (true) {
        ssize_t sent_bytes = sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&target_addr, sizeof(target_addr));
        if (sent_bytes < 0) {
            std::cerr << "Error sending data" << std::endl;
        } else {
            std::cout << "Forwarded " << sent_bytes << " bytes to " << TARGET_IP << ":" << TARGET_PORT << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

int main() {  
    std::vector<std::thread> threads;
    for (int i = 0; i < 20; ++i) {
        threads.emplace_back(handle_client, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}