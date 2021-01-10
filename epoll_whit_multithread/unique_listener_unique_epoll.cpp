#include "util.h"
#include "worker.h"
#include "epoll_unique.h"

void TestReusePortListener(const std::string& ip, short port, int thread_num) {
    uint64_t sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cout << "create socket failed." << std::endl;
        return;
    }
    SetSocketNoblocking(sock);
    if (!Bind(sock, port, ip)) {
        std::cout << "bind socket failed." << std::endl;
        return;
    }
    if (!Listen(sock)) {
        std::cout << "listen socket failed." << std::endl;
        return;
    }

    CWorkers works(std::make_shared<CEpollUniqueFactory>());
    works.Init(sock, thread_num);

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
