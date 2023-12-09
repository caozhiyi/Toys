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
