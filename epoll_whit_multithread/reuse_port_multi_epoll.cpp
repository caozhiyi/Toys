#include "util.h"
#include "worker.h"
#include "epoll_pre_thread.h"

void TestReusePortListener(const std::string& ip, short port, int thread_num) {
    std::vector<uint64_t> socks;
    for (int i = 0; i < thread_num; i++) {
        int sock = socket(PF_INET, SOCK_STREAM, 0);
        SetSocketNoblocking(sock);
        SetReusePort(sock);
        
        if (!Bind(sock, port, ip)) {
            std::cout << "bind socket failed. sock " << sock << std::endl;
            return;
        }
        if (!Listen(sock)) {
            std::cout << "listen socket failed." << std::endl;
            return;
        }
        std::cout << "bind socket success. sock " << sock << std::endl;

        socks.push_back(sock);
    }
    
    CWorkers works(std::make_shared<CEpollPerThreadFactory>());
    works.Init(socks);

    works.Run();
}


int main(int argc, char **argv) {
    if (argc < 4) {
		std::cout << "please ser params: <local_ip> <port> <thread_count>"<< std::endl;
		exit(0);
	}
	std::string ip = argv[1];
	short port = atoi(argv[2]);
	int thread_num = atoi(argv[3]);
    TestReusePortListener(ip, port, thread_num);
}