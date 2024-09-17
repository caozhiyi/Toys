/*
给定一个二叉树：
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
初始状态下，所有 next 指针都被设置为 NULL 。
*/
#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        queue_.push(root);
        connect();

        return root;
    }

    void connect() {
        int size = queue_.size();
        if (size == 0) {
            return;
        }
        
        Node* right = nullptr;
        while (size > 0) {
            Node* cur = queue_.front();
            queue_.pop();

            cur->next = right;
            right = cur;

            if (cur->right) {
                queue_.push(cur->right);
            }
            if (cur->left) {
                queue_.push(cur->left);
            }
            
            size--;
        }

        connect();
    } 

private:
    std::queue<Node*> queue_;
};