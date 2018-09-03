// Source : https://leetcode-cn.com/problems/min-stack/description/
// Number : 155
// Author : HL
// Date   : 2018-09-03
// Kill   : 97.85%

/********************************************************************************** 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
**********************************************************************************/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        Min = INT_MAX;
    }
    
    void push(int x) {
        if(x <= Min){
            sta.push(Min);
            sta.push(x);
            Min = x;
        }
        else
            sta.push(x);
        return;
    }
    
    void pop() {
        int nu = sta.top();
        if(nu == Min){
            sta.pop();
            Min = sta.top();
            sta.pop();
        }
        else
            sta.pop();
        return;
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return Min;
    }
private:
    stack<int> sta;
    int Min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
