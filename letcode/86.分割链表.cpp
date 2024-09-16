/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
你应当 保留 两个分区中每个节点的初始相对位置。
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* before_head_max = new ListNode;
        ListNode* before_head_min = new ListNode;

        ListNode* max_tail = nullptr;
        ListNode* min_tail = nullptr;

        ListNode* cur_node = head;
        while (cur_node) {
            if (cur_node->val < x) {
                if (min_tail == nullptr) {
                    before_head_min->next = cur_node;
                    min_tail = cur_node;

                } else {
                    min_tail->next = cur_node;
                    min_tail = min_tail->next;
                }

            } else {
                if (max_tail == nullptr) {
                    before_head_max->next = cur_node;
                    max_tail = cur_node;

                } else {
                    max_tail->next = cur_node;
                    max_tail = max_tail->next;
                }
            }
            cur_node = cur_node->next;
        }

        if (min_tail) {
            min_tail->next = before_head_max->next;
        }
        if (max_tail) {
            max_tail->next = nullptr;
        }
        
        return before_head_min->next ? before_head_min->next : before_head_max->next;
    }
};