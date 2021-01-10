#ifndef HEADER_WORKER_WORKER
#define HEADER_WORKER_WORKER

#include <vector>
#include <memory>
#include <thread>
#include <functional>

#include "epoll_interface.h"
#include "epoll_create_factory.h"

class CWorkers {
public:
    CWorkers(std::shared_ptr<CEpollFactory> factory);
    ~CWorkers();

    bool Init(uint64_t sock, int thread_num);

    bool Init(std::vector<uint64_t> socks);

    void Run();
private:
    std::shared_ptr<CEpollFactory> _epoll_factory;
    std::vector<std::shared_ptr<CEpoll>>      _epoll_vec;
    std::vector<std::shared_ptr<std::thread>> _thread_vec;
};

#endif