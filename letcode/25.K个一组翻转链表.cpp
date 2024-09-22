/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/

#include <vector>

using namespace std;

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
        vector<pair<ListNode*, ListNode*>> nodes;

        ListNode* cur = head;
        int count = 1;
        while (cur && cur->next) {
            cur = cur->next;
            count++;

            if (count == k) {
                ListNode* cur_start = head;
                ListNode* end = cur;

                cur = cur->next;
                head = cur;
                if (cur) {
                    count = 1;

                }
                else {
                    count = 0;
                }
                reverseGroup(cur_start, end);
                nodes.push_back({ end, cur_start });
            }
        }

        if (count > 0) {
            nodes.push_back({ head, cur });
        }

        ListNode* new_head = nullptr;
        ListNode* tail = nullptr;
        for (auto iter = nodes.begin(); iter != nodes.end(); iter++) {
            if (new_head == nullptr) {
                new_head = iter->first;
                tail = iter->second;

            }
            else {
                tail->next = iter->first;
                tail = iter->second;
            }
        }
        return new_head;
    }

    void reverseGroup(ListNode* head, ListNode* end) {
        if (head == end) {
            return;
        }

        if (head->next == end) {
            head->next = nullptr;
            end->next = head;
            return;
        }

        ListNode* left = head;
        ListNode* mid = left->next;
        ListNode* right = mid->next;
        ListNode* real_end = end->next;
        while (mid != real_end) {
            mid->next = left;

            left = mid;
            mid = right;
            if (right) {
                right = right->next;
            }
        }
        head->next = nullptr;
    }
};
