/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.
*/

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double weight = values[i];
            graph[u][v] = weight;
            graph[v][u] = 1.0 / weight;
        }
        int m = queries.size();
        vector<double> results(m, -1.0);
        for (int i = 0; i < m; i++) {
            string start = queries[i][0];
            string target = queries[i][1];
            if (!graph.count(start) || !graph.count(target)) {
                continue;
            }
            if (start == target) {
                results[i] = 1.0;
                continue;
            }
            queue<pair<string, double>> q;
            unordered_map<string, bool> visited;
            q.push({start, 1.0});
            visited[start] = true;
            while (!q.empty()) {
                string curr = q.front().first;
                double currVal = q.front().second;
                q.pop();
                if (curr == target) {
                    results[i] = currVal;
                    break;
                }
                for (auto neighbor : graph[curr]) {
                    string next = neighbor.first;
                    double nextVal = neighbor.second;
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push({next, currVal * nextVal});
                    }
                }
            }
        }
        return results;
    }
};

