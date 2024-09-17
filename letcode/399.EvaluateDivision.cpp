/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.
*/
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution {
private:
class Node {
public:
    std::unordered_map<std::string, Node*> next;
    double relationship;
    std::string key;

public:
    Node(const std::string& from) {
        key = from;
    }

    void addNext(const std::string& from, const std::string& to, double relationship) {
        Node* node = new Node(to);
        node->relationship = relationship;
        next[to] = node;
    }

    Node* find(const std::string& from) {
        if (next.count(from)) {
            return next[from];
        }
        if (next.empty()) {
            return nullptr;
        }
        for (auto iter = next.begin(); iter != next.end(); iter++) {
            if (iter->second->find(from)) {
                return iter->second;
            }
        }
        return nullptr;
    }

    double queryPath(const std::string& to) {
        if (next.count(to)) {
            return relationship;
        }

        if (next.empty()) {
            return -1;
        }
        double ret = queryPath(to);
        if (ret < 0) {
            return -1;
        }
        return relationship * ret;
    }
};


class NodeGroup {
private:
    std::unordered_map<std::string, Node*> roots;
public:
    void addNext(const std::string& from, const std::string& to, double relationship) {
        if (roots.count(from)) {
            roots[from]->addNext(from, to, relationship);
            return;
        }
        for (auto iter = roots.begin(); iter != roots.end(); iter++) {
            auto node = iter->second->find(from);
            if (node) {
                node->addNext(from, to, relationship);
                return;
            }
        }
        Node* node = new Node(to);
        node->relationship = relationship;
        roots[from] = node;
    }

    double calc(const std::string& from, const std::string& to) {
        if (roots.count(from)) {
            return roots[from]->queryPath(to);
        }
        for (auto iter = roots.begin(); iter != roots.end(); iter++) {
            auto node = iter->second->find(from);
            if (node) {
                return node->queryPath(to);
            }
        }
        return -1;
    }
};

public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations,
        std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        
        NodeGroup group;
        for (int i = 0; i < equations.size(); i++) {
            group.addNext(equations[i][0], equations[i][1], values[i]);
            group.addNext(equations[i][1], equations[i][0], 1 / values[i]);
        }
        
        std::vector<double> ret;
        for (size_t i = 0; i < queries.size(); i++) {
            ret.push_back(group.calc(queries[i][0], queries[i][1]));
        }
        return ret;
    }
};