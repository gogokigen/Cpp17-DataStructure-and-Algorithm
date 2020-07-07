https://www.geeksforgeeks.org/queue-linked-list-implementation/
#include <iostream>

using namespace std;

// Declare linked list node 
  
struct Node { 
    int data; 
    struct Node* next;
    Node(int d) { 
        data = d; 
        next = NULL; 
    }
};


class Queue{
public:
    Node *front, *rear; 
    Queue() { 
        front = rear = NULL; 
    } 
  
    void enQueue(int x) { 
  
        // Create a new LL node 
        Node* temp = new Node(x); 
  
        // If queue is empty, then 
        // new node is front and rear both 
        if (rear == NULL) { 
            front = rear = temp; 
            return; 
        } 
  
        // Add the new node at 
        // the end of queue and change rear 
        rear->next = temp; 
        rear = temp; 
    } 
  
    // Function to remove 
    // a key from given queue q 
    void deQueue() { 
        // If queue is empty, return NULL. 
        if (front == NULL) 
            return; 
  
        // Store previous front and 
        // move front one node ahead 
        Node* temp = front; 
        front = front->next; 
  
        // If front becomes NULL, then 
        // change rear also as NULL 
        if (front == NULL) 
            rear = NULL; 
  
        delete (temp); 
    }

};

int main(){

    Queue* q = new Queue;

    q->enQueue(10); 
    q->enQueue(20); 
    q->deQueue(); 
    q->deQueue(); 
    q->enQueue(30); 
    q->enQueue(40); 
    q->enQueue(50); 
    q->deQueue(); 
    cout << "Queue Front : " << (q->front)->data << endl; 
    cout << "Queue Rear : " << (q->rear)->data << endl;  


    return 0;
}