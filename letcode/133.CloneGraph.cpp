/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
*/

#include <vector>
#include <unordered_map>
// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        
        std::unordered_map<Node*, Node*> map;
        auto root = cloneGraph(node, map);
        for (auto iter = map.begin(); iter != map.end(); iter++) {
            for (int i = 0; i < iter->second->neighbors.size(); i++) {
                iter->second->neighbors[i] = map[iter->first->neighbors[i]];
            }
        }
        return root;
    }

    Node* cloneGraph(Node* node, std::unordered_map<Node*, Node*>& map) {
        Node* new_node = new Node(node->val, node->neighbors);
        map[node] = new_node;

        for (int i = 0; i < node->neighbors.size(); i++) {
            if (map.count(node->neighbors[i])) {
                continue;
            }
            cloneGraph(node->neighbors[i], map);
        }
        
        return new_node;
    }
};