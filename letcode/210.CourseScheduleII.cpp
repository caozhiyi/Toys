/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/

#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<vector<int>> depended_course; // index->course value-> list who depend the course
        depended_course.resize(numCourses);
        std::vector<int> depended_count; // index->course value->depend course count
        depended_count.resize(numCourses);
        for (size_t i = 0; i < numCourses; i++) {
            depended_count[i] = 0;
        }

        for (size_t i = 0; i < prerequisites.size(); i++) {
            depended_course[prerequisites[i][1]].push_back(prerequisites[i][0]);
            depended_count[prerequisites[i][0]]++;
        }
        
        vector<int> ret;
        queue<int> learned_course;
        for (int i = 0; i < depended_count.size(); i++) {
            if (depended_count[i] == 0) {
                ret.push_back(i);
                learned_course.push(i);
            }
        }
        
        while (!learned_course.empty()) {
            int course = learned_course.front();
            learned_course.pop();

            for (int i : depended_course[course]) {
                depended_count[i]--;
                if (depended_count[i] == 0) {
                    learned_course.push(i);
                    ret.push_back(i);
                }
            }
        }
        if (ret.size() == numCourses) {
            return ret;
        }
        
        return {};
    }
};