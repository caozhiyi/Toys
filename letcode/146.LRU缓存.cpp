/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

#include <memory>
#include <unordered_map>

class LRUCache {
    struct ListNode {
        int key;
        int value;
        std::shared_ptr<ListNode> next;
        std::shared_ptr<ListNode> prev;
    };

public:
    LRUCache(int capacity) : capacity_(capacity) {
        map_.reserve(capacity);
        head_ = std::make_shared<ListNode>();
        end_ = std::make_shared<ListNode>();
        head_->next = end_;
        end_->prev = head_;
    }

    int get(int key) {
        int ret = -1;
        auto iter = map_.find(key);
        if (iter != map_.end()) {
            ret = iter->second->value;
            moveToHead(iter->second);
        }
        return ret;
    }

    void put(int key, int value) {
        auto iter = map_.find(key);
        if (iter != map_.end()) {
            auto del_node = iter->second;

            del_node->value = value;
            moveToHead(del_node);
            return;
        }

        if (map_.size() >= capacity_) {
            auto del_node = end_->prev;
            map_.erase(del_node->key);

            del_node->key = key;
            del_node->value = value;
            moveToHead(del_node);
            map_[key] = del_node;

        } else {
            auto node = std::make_shared<ListNode>();
            node->key = key;
            node->value = value;
            moveToHead(node);
            map_[key] = node;
        }
    }
private:
    void moveToHead(std::shared_ptr<ListNode> node) {
        // remove
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }

        // add to head
        head_->next->prev = node;
        node->next = head_->next;
        node->prev = head_;
        head_->next = node;
    }

private:
    std::unordered_map<int, std::shared_ptr<ListNode>> map_;
    std::shared_ptr<ListNode> head_;
    std::shared_ptr<ListNode> end_;
    int capacity_;
};