#include <vector>
#include <memory>
#include <thread>
#include <functional>

#include "worker.h"
#include "epoll_interface.h"
#include "epoll_create_factory.h"

CWorkers::CWorkers(std::shared_ptr<CEpollFactory> factory) : _epoll_factory(factory) {
    
}

CWorkers::~CWorkers() {

}

bool CWorkers::Init(uint64_t sock, int thread_num) {
    for (size_t i = 0; i < thread_num; i++){
        auto ep = _epoll_factory->CreateEpoll();
        ep->AddListener(sock);
        _epoll_vec.push_back(ep);
    }
    return true;
}

bool CWorkers::Init(std::vector<uint64_t> socks) {
    for (size_t i = 0; i < socks.size(); i++){
        auto ep = _epoll_factory->CreateEpoll();
        ep->AddListener(socks[i]);
        _epoll_vec.push_back(ep);
    }
    return true;
}

void CWorkers::Run() {
    for (size_t i = 0; i < _epoll_vec.size(); i++) {
        std::shared_ptr<std::thread> thd(new std::thread(std::bind(&CEpoll::Loop, _epoll_vec[i])));
        _thread_vec.push_back(thd);
    }
    for (size_t i = 0; i < _thread_vec.size(); i++) {
        _thread_vec[i]->join();
    }
}
