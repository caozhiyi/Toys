/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
*/
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }

        // consider cur postion
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();

        // do not consider cur postion
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};