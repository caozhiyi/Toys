#ifndef HEADER_EPOLL_EPOLL_EXCLUSIVE_PRE_THREAD
#define HEADER_EPOLL_EPOLL_EXCLUSIVE_PRE_THREAD

#include "epoll_pre_thread.h"
#include "epoll_create_factory.h"

class CEpollExclusivePerThread: public CEpollPerThread {
public:
    CEpollExclusivePerThread();
    virtual ~CEpollExclusivePerThread();

    virtual bool AddListener(uint64_t sock);
};

class CEpollExclusivePerThreadFactory : public CEpollFactory {
public:
    CEpollExclusivePerThreadFactory() {}
    virtual ~CEpollExclusivePerThreadFactory() {}

    virtual std::shared_ptr<CEpoll> CreateEpoll() {
        return std::make_shared<CEpollExclusivePerThread>();
    }
};

#endif