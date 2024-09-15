/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
*/

#include <stack>
#include <algorithm>

class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        data_stack_.push(val);
        if (min_stack_.empty()) {
            min_stack_.push(val);

        } else {
            min_stack_.push(std::min(min_stack_.top(), val));
        }
    }
    
    void pop() {
        min_stack_.pop();
        data_stack_.pop();
    }
    
    int top() {
        return data_stack_.top();
    }
    
    int getMin() {
        return min_stack_.top();
    }
private:
    std::stack<int> data_stack_;
    std::stack<int> min_stack_;
};
