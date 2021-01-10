#ifndef HEADER_EPOLL_EPOLL_EXCLUSIVE_UNIQUE
#define HEADER_EPOLL_EPOLL_EXCLUSIVE_UNIQUE

#include "epoll_unique.h"
class CEpollExclusiveUnique: public CEpollUnique {
public:
    CEpollExclusiveUnique();
    virtual ~CEpollExclusiveUnique();
    virtual bool AddListener(uint64_t sock);
};


class CEpollExclusiveUniqueFactory : public CEpollFactory {
public:
    CEpollExclusiveUniqueFactory() {}
    virtual ~CEpollExclusiveUniqueFactory() {}

    virtual std::shared_ptr<CEpoll> CreateEpoll() {
        return std::make_shared<CEpollExclusiveUnique>();
    }
};

#endif