struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;
        ListNode* p4 = nullptr;

        ListNode* ret_head = nullptr;
        while (true) {
            if (ret_head == nullptr) {
                // first 
                p2->next = p1;
                p1->next = p3;
                ret_head = p2;

                p1 = ret_head->next;

            } else {
                p1->next = p3;
                p2->next = p4;
                p3->next = p2;

                p1 = p1->next->next;
            }
            
            // next nodes
            if (p1) {
                p2 = p1->next;

            } else {
                break;
            }

            if (p2) {
                p3 = p2->next;

            } else {
                break;
            }

            if (p3) {
                p4 = p3->next;

            } else {
                break;
            }
        }
        
        return ret_head;
    }
};


class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* one = head;
        ListNode* two = one->next;
        ListNode* three = two->next;
        
        one->next = three;
        two->next = one;
        
        one->next = swapPairs(three);
        return two;
    }
};