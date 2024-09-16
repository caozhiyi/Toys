/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* new_head = nullptr;
        ListNode* new_tail = nullptr;

        ListNode* node1 = head;
        ListNode* node2 = head->next;
        
        while (node1) {
            bool add = true;
            while (node1 && node2 && node1->val == node2->val) {
                add = false;
                node2 = node2->next;
            }

            if (add) {
                if (new_head == nullptr) {
                    new_head = node1;
                    new_tail = node1;
                    new_tail->next = nullptr;

                }
                else {
                    new_tail->next = node1;
                    new_tail = new_tail->next;
                    new_tail->next = nullptr;
                }
            } 

            // move 1 step
            node1 = node2;
            node2 = node2 ? node2->next : nullptr;
        }
        return new_head;
    }
};
