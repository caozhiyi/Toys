#include <stack>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }

        std::stack<ListNode*> node_stack;
        ListNode* cur_node = head;
        int len = 0;
        while (cur_node) {
            node_stack.push(cur_node);
            cur_node = cur_node->next;
            len++;
        }

        k = k % len;
        if (k == len || len == 1) {
            return head;
        }

        ListNode* before_node = new ListNode;
        before_node->next = head;
        
        while (k > 0) {
            k--;
            ListNode* node = node_stack.top();
            node_stack.pop();
            node->next = before_node->next;
            before_node->next = node;
        }

        ListNode* node = node_stack.top();
        node_stack.pop();
        node->next = nullptr;

        return before_node->next;
    }
};