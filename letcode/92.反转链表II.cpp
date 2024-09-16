/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) {
            return nullptr;
        }

        if (left == right) {
            return head;
        }
        ListNode* left_node = nullptr;
        ListNode* right_node = nullptr;

        ListNode* rev_head = nullptr;
        ListNode* rev_end = nullptr;

        ListNode* cur = head;
        while (cur) {
            left--;
            if (left == 1) {
                left_node = cur;
            }
            if (left == 0) {
                rev_head = cur;
            }

            right--;
            if (right == 0) {
                rev_end = cur;
            }
            if (right == -1) {
                right_node = cur;
            }

            cur = cur->next;
        }

        reverse(rev_head, rev_end);
        if (left_node) {
            left_node->next = rev_end;
        }
        if (rev_head) {
            rev_head->next = right_node;
        }
        
        if (left_node == nullptr) {
            return rev_end;
        }
        return head;
    }

    void reverse(ListNode* head, ListNode* end) {
        ListNode* left = head;
        ListNode* middle = left ? left->next : nullptr;
        ListNode* right = middle ? middle->next : nullptr;
        while (middle != nullptr) {
            middle->next = left;

            left = middle;
            middle = right;

            if (right) {
                right = right->next;
            } else {
                break;
            }
           
            if (left == end) {
                break;
            }
        }
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) {
            return nullptr;
        }

        if (left == right) {
            return head;
        }

        ListNode* before_head = new ListNode;
        before_head->next = head;

        ListNode* link_node = nullptr;
        ListNode* prev_node = before_head;
        ListNode* cur_node = before_head;

        bool start_reverse = false;
        while (cur_node) {
            if (left == 1) {
                link_node = cur_node;
                // filter before head
                if (link_node == before_head) {
                    cur_node = cur_node->next;
                }
                start_reverse = true;
            }
            left--;
            if (!start_reverse) {
                prev_node = cur_node;
                cur_node = cur_node->next;
                continue;
            }
            
            // get node from list
            if (prev_node) {
                prev_node->next = cur_node->next;
            }
            
            // add node to list
            cur_node->next = link_node->next;
            link_node->next = cur_node;

            right--;
            if (right == 0) {
                break;
            }

            prev_node = cur_node;
            cur_node = cur_node->next;
        }

        auto ret = before_head->next;
        delete before_head;
        return ret;
    }
};
