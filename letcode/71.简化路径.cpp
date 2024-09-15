/*
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为 更加简洁的规范路径。
在 Unix 风格的文件系统中规则如下：
一个点 '.' 表示当前目录本身。
此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件/目录名称。
返回的 简化路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。
*/
#include <stack>
#include <string>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> str_stack;

        std::string cur;
        for (auto iter = path.begin(); iter != path.end(); iter++) {
            if (*iter == '/') {
                if (!cur.empty()) {
                    str_stack.push(cur);
                    cur.clear();
                }

            } else {
                cur += *iter;
            }
        }
        if (!cur.empty()) {
            str_stack.push(cur);
        }

        std::string ret;
        int remove_count = 0;
        while (!str_stack.empty()) {
            cur = str_stack.top();
            str_stack.pop();

            if (cur == ".") {
                continue;

            } else if (cur == "..") {
                remove_count++;

            } else {
                if (remove_count > 0) {
                    remove_count--;
                    continue;
                }
                
                if (ret.empty()) {
                    ret = cur;

                } else {
                    ret = cur + "/" + ret;
                }
            }
        }
        return "/" + ret;
    }
};