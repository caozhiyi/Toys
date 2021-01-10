#ifndef HEADER_EPOLL_EPOLL_PRE_THREAD
#define HEADER_EPOLL_EPOLL_PRE_THREAD

#include "epoll_interface.h"
#include "epoll_create_factory.h"

class CEpollPerThread: public CEpoll {
public:
    CEpollPerThread();
    virtual ~CEpollPerThread();

    virtual bool AddListener(uint64_t sock);
    virtual void Loop();

    virtual void OnAccet(uint64_t sock);

protected:
    int32_t _epoll_handler;
};

class CEpollPerThreadFactory : public CEpollFactory {
public:
    CEpollPerThreadFactory() {}
    virtual ~CEpollPerThreadFactory() {}

    virtual std::shared_ptr<CEpoll> CreateEpoll() {
        return std::make_shared<CEpollPerThread>();
    }
};

#endif