/*******************************************************************
* https://leetcode.com/problems/min-stack/
* Easy
* 
* Conception: 
*  1. 
*
* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*
*    push(x) -- Push element x onto stack.
*    pop() -- Removes the element on top of the stack.
*    top() -- Get the top element.
*    getMin() -- Retrieve the minimum element in the stack.
*
*
* Example:
*
*
* Key:
*  1. 
*
* Advanced:
*  1. 
*
*******************************************************************/
// Method 1: easy but slow
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        minStack.push_back(x);
    }
    
    void pop() {
        minStack.pop_back();
    }
    
    int top() {
        return minStack.back();
    }
    
    int getMin() {
        int ret = INT_MAX;
        for(auto i: minStack){
            if(i < ret){
                ret = i;
            }
        }
        return ret;
    }
private:
    vector<int> minStack;
};

//Method 2: faster
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        minStack.push_back(x);
        
        // update min
        if (x < min) {
            min = x;
        }
    }
    
    void pop() {
        // update min
        if (top() == min) {
            if (minStack.size() == 1) {
                min = INT_MAX;
            } else {
                min = minStack[0];
            }
            for (size_t i = 0; i < minStack.size() - 1; ++i) {
                if (minStack[i] < min) {
                    min = minStack[i];
                }
            }
        }
        
        minStack.pop_back();
    }
    
    int top() {
        return minStack[minStack.size() - 1];
    }
    
    int getMin() {
        return min;
    }
private:
    vector<int> minStack;
    int min = INT_MAX;;
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */