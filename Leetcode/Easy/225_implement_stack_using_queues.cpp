/*******************************************************************
* https://leetcode.com/problems/implement-stack-using-queues/
* Easy
* 
* Conception: 
*  1. 
*
*
* Key:
*  1. 
*
* Reference:
*  1. https://zxi.mytechroad.com/blog/data-structure/leetcode-225-implement-stack-using-queues/
*
*******************************************************************/
class MyStack {
    queue<int> stack, tmp;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        tmp.push(x);
        while(tmp.size() > 1){
            stack.push(tmp.front());
            tmp.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = top();
        tmp.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        if(tmp.empty()){
            for(int i = 0; i < stack.size() - 1; i++){
                stack.push(stack.front());
                stack.pop();
            }
            tmp.push(stack.front());
            stack.pop();
        }
        return tmp.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return tmp.empty() && stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */