#include <vector>
#include <iostream>
#include <unistd.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/resource.h>

#include "epoll_pre_thread.h"

CEpollPerThread::CEpollPerThread() : _epoll_handler(-1) {
    _epoll_handler = epoll_create(1500);
    if (_epoll_handler == -1) {
        std::cout << "create epoll handle failed." << std::endl;
        abort();
    }
}

CEpollPerThread::~CEpollPerThread() {
    if (_epoll_handler > 0) {
        close(_epoll_handler);
    }
}

bool CEpollPerThread::AddListener(uint64_t sock) {
    epoll_event *event = new epoll_event;
    event->data.u64 = sock;
    event->events |= EPOLLIN|EPOLLOUT|EPOLLRDHUP;
    int res = epoll_ctl(_epoll_handler, EPOLL_CTL_ADD, sock, event);
    if (res == -1) {
        std::cout << "remove event from epoll faild! error " << std::endl;
        return false;
    }
    std::cout << "add event to epoll " << std::endl;
    return true;
}

void CEpollPerThread::Loop()  {
    std::cout << "loop start run" << std::endl;
    std::vector<epoll_event> event_vec;
    event_vec.resize(1000);
    while(true) {
        int res = epoll_wait(_epoll_handler, &*event_vec.begin(), (int)(event_vec.size()), -1);
        if (res == -1) {
            std::cout << "epoll_wait faild! error " << errno << std::endl;
            abort();
        }
        std::cout <<"epoll_wait weak up " << std::endl;
        for (size_t i = 0; i < res; i++) {
            uint64_t sock = event_vec[i].data.u64;
            OnAccet(sock);
        }
    }
}

void CEpollPerThread::OnAccet(uint64_t sock)  {
    sockaddr_in client_addr;
    socklen_t addr_size = 0;
    int new_sock = accept(sock,  (sockaddr*)&client_addr, &addr_size);
    if (new_sock < 0) {
        std::cout << "epoll_wait weak up and get a connection failed." << std::endl;
    } else {
        close(new_sock);
        std::cout << "epoll_wait weak up and get a connection success." << std::endl;
    }
}
