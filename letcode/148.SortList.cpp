/*
Given the head of a linked list, return the list after sorting it in ascending order.
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
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* end) {
        if (head == nullptr) {
            return nullptr;
        }

        if (head->next == end) {
            head->next = nullptr;
            return head;
        }

        auto slow = head;
        auto fast = head;
        while (fast != end) {
            slow = slow->next;
            fast = fast->next;
            if (fast != end) {
                fast = fast->next;
            }
        }
        ListNode* left = sortList(head, slow);
        ListNode* right = sortList(slow, end);

        return mergeList(left, right);
    }

    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* ret = nullptr;
        ListNode* cur = nullptr;
        bool can_break = false;
        while (!can_break && (left != nullptr || right != nullptr)) {
            ListNode* target = nullptr;
            if (left != nullptr && right != nullptr) {
                if (left->val < right->val) {
                    target = left;
                    left = left->next;

                } else {
                    target = right;
                    right = right->next;
                }

            } else if (left != nullptr) {
                target = left;
                left = left->next;
                can_break = true;

            } else if (right != nullptr) {
                target = right;
                right = right->next;
                can_break = true;
            }

            if (ret == nullptr) {
                ret = target;
                cur = target;

            } else {
                cur->next = target;
                cur = target;
            }
        }
        return ret;
    }
};
