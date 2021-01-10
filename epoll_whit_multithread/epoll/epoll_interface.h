#ifndef HEADER_EPOLL_EPOLL_INTERFACE
#define HEADER_EPOLL_EPOLL_INTERFACE

#include <stdint.h>
class CEpoll {
public:
    CEpoll() {}
    virtual ~CEpoll() {}

    virtual bool AddListener(uint64_t sock) = 0;
    virtual void Loop() = 0;

    virtual void OnAccept(uint64_t sock) = 0;
};

#endif