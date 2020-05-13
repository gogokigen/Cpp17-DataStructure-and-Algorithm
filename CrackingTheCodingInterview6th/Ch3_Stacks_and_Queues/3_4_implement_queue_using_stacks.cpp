/*******************************************************************
* https://leetcode.com/problems/implement-queue-using-stacks/
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
*  1. 
*
*******************************************************************/
class MyQueue {
    stack<int> queue, tmp;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        queue.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!queue.empty()){
            tmp.push(queue.top());
            queue.pop();
        }
        int ret = tmp.top();
        tmp.pop();
        while(!tmp.empty()){
            queue.push(tmp.top());
            tmp.pop();
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        while(!queue.empty()){
            tmp.push(queue.top());
            queue.pop();
        }
        int ret = tmp.top();
        while(!tmp.empty()){
            queue.push(tmp.top());
            tmp.pop();
        }
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */