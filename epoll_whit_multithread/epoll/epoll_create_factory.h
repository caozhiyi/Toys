#ifndef HEADER_EPOLL_EPOLL_CREATE_FACTORY
#define HEADER_EPOLL_EPOLL_CREATE_FACTORY

#include <memory>
#include "epoll_interface.h"

class CEpollFactory {
public:
    CEpollFactory() {}
    virtual ~CEpollFactory() {}

    virtual std::shared_ptr<CEpoll> CreateEpoll() = 0;
};

#endif