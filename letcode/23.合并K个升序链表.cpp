/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
*/
#include <map>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        std::map<int, std::vector<ListNode*>> tamp_map;
        for (size_t i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                tamp_map[lists[i]->val].push_back(lists[i]);
            }
        }
        while (!tamp_map.empty()) {
            // get little one
            auto iter = tamp_map.begin();
            int remove_val = iter->first;

            for (size_t i = 0; i < iter->second.size(); i++) {
                if (tail == nullptr) {
                    tail = iter->second[i];
                    head = tail;

                } else {
                    tail->next = iter->second[i];
                    tail = tail->next;
                }

                ListNode* temp = iter->second[i]->next;
                if (temp) {
                    tamp_map[temp->val].push_back(temp);
                }
                
            }
            tamp_map.erase(remove_val);
        }
        return head;
    }
};

class Solution1 {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        if (left == right) {
            return lists[left];
        }

        if (left + 1 == right) {
            return mergeTwoLists(lists[left], lists[right]);
        }
        
        return mergeTwoLists(mergeKLists(lists, left, (left + right) / 2),
                             mergeKLists(lists, (left + right) / 2 + 1, right));
    }

    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        ListNode* ret = nullptr;
        ListNode* cur = nullptr;
        ListNode* target = nullptr;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                target = left;
                left = left->next;

            } else {
                target = right;
                right = right->next;
            }
            
            if (ret == nullptr) {
                ret = target;
                cur = target;
            } else {
                cur->next = target;
                cur = target;
            }
        }
        
        if (left != nullptr) {
            if (ret == nullptr) {
                ret = left;
            } else {
                cur->next = left;
            }
        }
        if (right != nullptr) {
            if (ret == nullptr) {
                ret = right;
            } else {
                cur->next = right;
            }
        }
        return ret;
    }
};