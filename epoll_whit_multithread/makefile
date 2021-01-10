SRCS = $(wildcard ./epoll/*.cpp ./worker/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

CC = g++

INCLUDES = -I.           \
           -I./epoll     \
           -I./worker    \

CCFLAGS = -lpthread -fPIC -m64 -g -pg -std=c++11 -lstdc++ -pipe 

ReusePortMultiEpoll = reuse_port_multi_epoll
ReusePortMultiEpollSrc = reuse_port_multi_epoll.cpp

ReusePortUniqueEpoll = reuse_port_unique_epoll
ReusePortUniqueEpollSrc = reuse_port_unique_epoll.cpp

UniqueListenerMultiEpoll = unique_listener_multi_epoll
UniqueListenerMultiEpollSrc = unique_listener_multi_epoll.cpp

UniqueListenerUniqueEpoll = unique_listener_unique_epoll
UniqueListenerUniqueEpollSrc = unique_listener_unique_epoll.cpp

all: $(ReusePortMultiEpoll) $(ReusePortUniqueEpoll) $(UniqueListenerMultiEpoll) $(UniqueListenerUniqueEpoll)

$(ReusePortMultiEpoll):$(OBJS) $(ReusePortMultiEpollSrc)
	$(CC) $^ -o $@  $(TARGET)  $(CCFLAGS) $(INCLUDES)

$(ReusePortUniqueEpoll):$(OBJS) $(ReusePortUniqueEpollSrc)
	$(CC) $^ -o $@  $(TARGET)  $(CCFLAGS) $(INCLUDES)

$(UniqueListenerMultiEpoll):$(OBJS) $(UniqueListenerMultiEpollSrc)
	$(CC) $^ -o $@  $(TARGET)  $(CCFLAGS) $(INCLUDES)

$(UniqueListenerUniqueEpoll):$(OBJS) $(UniqueListenerUniqueEpollSrc)
	$(CC) $^ -o $@  $(TARGET)  $(CCFLAGS) $(INCLUDES)

%.o : %.cpp
	$(CC) -c $< -o $@ $(CCFLAGS) $(INCLUDES) 

clean:
	rm -rf $(OBJS) *.o $(ReusePortMultiEpoll) $(ReusePortUniqueEpoll) $(UniqueListenerMultiEpoll) $(UniqueListenerUniqueEpoll)