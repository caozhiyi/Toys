/*
Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.
*/

#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }

    Node* construct(vector<vector<int>>& grid, int row, int col, int len) {
        // the min grid
        if (len == 1) {
            Node* ret = new Node(grid[row][col], true);
            return ret;
        }
        
        // spilt grid
        // top left
        len = len / 2;
        Node* top_left = construct(grid, row, col, len);

        // top right
        Node* top_right = construct(grid, row, col + len, len);

        // bottom left
        Node* bottom_left = construct(grid, row + len, col, len);

        // bottom right
        Node* bottom_right = construct(grid, row + len, col + len, len);

        // check result
        if (top_left->val != top_right->val ||
            top_left->val != bottom_left->val ||
            top_left->val != bottom_right->val ||
            !top_left->isLeaf ||
            !top_right->isLeaf ||
            !bottom_left->isLeaf ||
            !bottom_right->isLeaf) {
            return new Node(true, false, top_left, top_right, bottom_left, bottom_right);

        } else {
            delete top_left;
            delete top_right;
            delete bottom_left;
            delete bottom_right;
            return new Node(grid[row][col], true);
        }
    }
};