/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int up = 0;
        ListNode* ret = new ListNode;
        ListNode* cur_node = ret;
        while (true) {
            int cur = up;
            up = 0;
            if (l1) {
                cur += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                cur += l2->val;
                l2 = l2->next;
            }
            
            if (cur >= 10) {
                up = cur / 10;
                cur = cur - 10;
            }

            cur_node->val = cur;
            if (l1 || l2 || up) {
                cur_node->next = new ListNode;
                cur_node = cur_node->next;
            } else {
                break;
            }
        }
        return ret;
    }
};
// @lc code=end

