struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ret_head = nullptr;
        ListNode* ret_tail = nullptr;

        int cur = 1;
        ListNode* cur_head = head;
        ListNode* cur_tail = head;
        ListNode* next_head = nullptr;
        while (cur_tail) {
            cur++;
            cur_tail = cur_tail->next;
            if (cur_tail == nullptr) {
                break;
            }

            if (cur >= k) {
                // reverse k list
                ListNode* p1 = cur_head;
                ListNode* p2 = p1->next;
                ListNode* p3 = p2->next;
                while (p2 != cur_tail->next && p3 != nullptr) {
                    p2->next = p1;

                    p1 = p2;
                    p2 = p3;
                    p3 = p3->next;
                }
                // link tail node
                cur_head->next = p3;

                // set return head
                if (ret_head == nullptr) {
                    ret_head = cur_tail;
                }

                if (ret_tail) {
                    ret_tail->next = cur_tail;
                    ret_tail = cur_head;

                } else if (ret_tail == nullptr) {
                    ret_tail = cur_head;
                }
            
                // next round
                cur_head = p3;
                cur_tail = cur_head;
                cur = 1;
            }
        }
        return ret_head;
    }
};