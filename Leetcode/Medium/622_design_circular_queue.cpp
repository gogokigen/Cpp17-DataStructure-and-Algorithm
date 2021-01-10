/*******************************************************************
* https://leetcode.com/problems/design-circular-queue/
* Medium
* 
* Conception: 
*  1. 
*
* Design your implementation of the circular queue.
* The circular queue is a linear data structure in 
* which the operations are performed based on FIFO (First In First Out) principle
* and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".
*
* One of the benefits of the circular queue is that we can make use of the spaces in front of the queue.
* In a normal queue, once the queue becomes full,
* we cannot insert the next element even if there is a space in front of the queue.
* But using the circular queue, we can use the space to store new values.
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1.
*
*******************************************************************/
class Node {
public:
    int value;
    Node *next;

    Node(int val): value(val), next(nullptr) {
    }
};

class MyCircularQueue {
private:
    Node *head = new Node(0), *tail = new Node(0);
    int count = 0;
    int capacity = 0;

public:
    MyCircularQueue(int k) {
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;

        Node *newNode = new Node(value);
        if (count == 0) {
          head = tail = newNode;
        } else {
          tail->next = newNode;
          tail = newNode;
        }

        count += 1;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        count -= 1;
        head = head->next;
        
        return true;
    }
    
    int Front() {
        if (count == 0){
            return -1;
        } else{
            return head->value;
        }
    }
    
    int Rear() {
        if (count == 0){
          return -1;
        }else{
          return tail->value;
        }
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};


class Node {
public:
    int value;
    Node *prev, *next;

    Node(int val): value(val), prev(nullptr), next(nullptr) {
    }
};


// double linkedlist
class MyCircularQueue {
private:
    Node *head = new Node(0), *tail = new Node(0);
    int count = 0;
    int capacity = 0;

public:
    MyCircularQueue(int k) {
        capacity = k;
        head -> next = tail;
        tail -> prev = head;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;

        Node *newNode = new Node(value);
        Node *prev = tail -> prev;

        prev->next = newNode;
        newNode->prev = prev;

        newNode->next = tail;
        tail->prev = newNode;

        count += 1;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        count -= 1;
        
        Node *tmpNode = head -> next;
        Node *next = tmpNode -> next;
        head -> next = next;
        next -> prev = head;
        tmpNode -> prev = tmpNode -> next = NULL;
        delete tmpNode;
        
        return true;
    }
    
    int Front() {
        if (count == 0){
            return -1;
        } else{
            return head->next->value;
        }
    }
    
    int Rear() {
        if (count == 0){
          return -1;
        }else{
          return tail->prev->value;
        }
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */