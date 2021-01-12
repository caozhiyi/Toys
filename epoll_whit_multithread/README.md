# epoll遇到多线程
由于epoll没有像IOCP一样接管线程调度，epoll的各种组合使用就很让人费解。这里将reuse_port, EPOLLEXCLUSIVE, epoll的各种组合在多线程情况下的表现，做了测试。

## 说明
我在这里将各种标识和多线程的结合做了测试，共实现了以下几种情况：   
+ unique_listener_unique_epoll：一个监听socket对应一个epoll句柄，放到多个线程epoll_wait
+ unique_listener_multi_epoll： 一个监听socket对应多个epoll句柄，每个线程一个epoll句柄
+ reuse_port_unique_epoll：     reuse_port多个监听socket对应一个epoll句柄，放到多个线程epoll_wait
+ reuse_port_multi_epoll：      reuse_port多个监听socket对应多个epoll句柄，每个线程一个epoll句柄
+ unique_listener_unique_exclusive_epoll： 一个监听socket设置EPOLLEXCLUSIVE标识，对应一个epoll句柄，放到多个线程epoll_wait
+ unique_listener_multi_exclusive_epoll：  一个监听socket设置EPOLLEXCLUSIVE标识，对应多个epoll句柄，每个线程一个epoll句柄

## 结果
|EPOLLEXCLUSIVE| reuse_port | 监听socket个数 | epoll句柄个数 | 线程数 | 唤醒线程数 |  成功accept线程数 |  是否惊群 |
| :---------:  | :---------:| :---------:   | :----:        | :----: | :----------: | :----------: |:----------:|
| ❌ | ❌| 1 | 1 | 8 |1~2 | 1 | ✅ |
| ❌ | ❌| 1 | 8 | 8 |3~8 | 1 | ✅ |
| ❌ | ✅| 8 | 1 | 8 |1~2 | 1 | ✅ |
| ❌ | ✅| 8 | 8 | 8 |1   | 1 | ❌ |
| ✅ | ❌| 1 | 1 | 8 |    |   |   |
| ✅ | ❌| 1 | 8 | 8 |    |   |   |
