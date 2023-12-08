
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        ListNode* new_node = nullptr;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                new_node = list2;
                list2 = list2->next;

            } else if (list2 == nullptr)  {
                new_node = list1;
                list1 = list1->next;

            } else {
                if (list1->val < list2->val) {
                    new_node = list1;
                    list1 = list1->next;
                    
                } else {
                    new_node = list2;
                    list2 = list2->next;
                }
            }
            
            if (tail == nullptr) {
                tail = new_node;
                head = new_node;

            } else {
                tail->next = new_node;
                tail = tail->next;
            }
        }
        return head;
    }
};