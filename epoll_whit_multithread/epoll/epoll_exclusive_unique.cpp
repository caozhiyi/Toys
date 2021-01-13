#include <vector>
#include <iostream>
#include <unistd.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/resource.h>

#include "epoll_exclusive_unique.h"

CEpollExclusiveUnique::CEpollExclusiveUnique() {
    if (_unique_epoll_handler < 0) {
        _unique_epoll_handler = epoll_create(1500);
        if (_unique_epoll_handler < 0) {
            std::cout << "create epoll handle failed." << std::endl;
            abort();
        }
    }
}

CEpollExclusiveUnique::~CEpollExclusiveUnique() {
    
}

bool CEpollExclusiveUnique::AddListener(uint64_t sock) {
    epoll_event *event = new epoll_event;
    event->data.u64 = sock;
    event->events = EPOLLIN|EPOLLOUT|EPOLLEXCLUSIVE;
    int res = epoll_ctl(_unique_epoll_handler, EPOLL_CTL_ADD, sock, event);
    if (res == -1) {
        std::cout << "add event to epoll faild! error " << errno << std::endl;
        return false;
    }
    std::cout << "add event to epoll " << std::endl;
    return true;
}