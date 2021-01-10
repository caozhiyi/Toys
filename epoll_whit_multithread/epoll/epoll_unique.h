#ifndef HEADER_EPOLL_EPOLL_UNIQUE
#define HEADER_EPOLL_EPOLL_UNIQUE

#include "epoll_pre_thread.h"
class CEpollUnique: public CEpoll {
public:
    CEpollUnique();
    virtual ~CEpollUnique();
    virtual bool AddListener(uint64_t sock);
    virtual void Loop();

    virtual void OnAccet(uint64_t sock);
private:
    static int32_t _unique_epoll_handler;
};


class CEpollUniqueFactory : public CEpollFactory {
public:
    CEpollUniqueFactory() {}
    virtual ~CEpollUniqueFactory() {}

    virtual std::shared_ptr<CEpoll> CreateEpoll() {
        return std::make_shared<CEpollUnique>();
    }
};

#endif