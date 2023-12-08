/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        }

        ListNode* prev_head = new ListNode();
        prev_head->next = head;

        ListNode* first_pt = prev_head;
        ListNode* target_pt =  prev_head;
        while (first_pt->next != nullptr) {
            if (n <= 0) {
                target_pt = target_pt->next;
            }

            first_pt = first_pt->next;
            n--;
        }

        // remove target node
        if (target_pt == prev_head) {
            head = head->next;

        } else {
            target_pt->next = target_pt->next->next;
        }
        delete prev_head;
        return head;
    }
};