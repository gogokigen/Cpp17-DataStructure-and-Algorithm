//https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
#include <iostream>

using namespace std;

// Declare linked list node 
  
struct Node { 
    int data; 
    struct Node* next; 
};


class Stack{
public:

struct Node* top;
int capacity = 0;
    
    Stack(int max_size):top(NULL), capacity(max_size){}

// Utility function to add an element data in the stack 
 // insert at the beginning 
void push(int data) { 
    // create new node temp and allocate memory 
    struct Node* temp; 
    temp = new Node(); 
  
    // check if stack (heap) is full. Then inserting an element would 
    // lead to stack overflow 
    if (!temp) { 
        cout << "\nHeap Overflow" << endl; 
        exit(1); 
    } 
  
    // initialize data into temp data field 
    temp->data = data; 
  
    // put top pointer reference into temp link 
    temp->next = this->top; 
  
    // make temp as top of Stack 
    this->top = temp; 
} 
  
// Utility function to check if the stack is empty or not 
int isEmpty() { 
    return this->top == NULL; 
} 
  
// Utility function to return top element in a stack 
int peek() { 
    // check for empty stack 
    if (!isEmpty()) 
        return this->top->data; 
    else
        exit(1); 
} 
  
// Utility function to pop top  
// element from the stack 
  
void pop() { 
    struct Node* temp; 
  
    // check for stack underflow 
    if (this->top == NULL) { 
        cout << "\nStack Underflow" << endl; 
        exit(1); 
    } 
    else { 
        // top assign into temp 
        temp = this->top; 
  
        // assign second node to top 
        this->top = this->top->next; 
  
        // destroy connection between first and second 
        temp->next = NULL; 
  
        // release memory of top node 
        free(temp); 
    } 
} 
  
// Function to print all the  
// elements of the stack  
void display()  { 
    struct Node* temp; 
  
    // check for stack underflow 
    if (this->top == NULL) { 
        cout << "\nStack Underflow"; 
        exit(1); 
    } 
    else { 
        temp = this->top; 
        while (temp != NULL) { 
  
            // print node data 
            cout <<  temp->data << " " << endl; 
  
            // assign temp link to temp 
            temp = temp->next; 
        } 
    } 
} 

};

int main(){

    Stack* sol = new Stack(6);
    
    sol->push(11); 
    sol->push(22); 
    sol->push(33); 
    sol->push(44); 
  
    // display stack elements 
    sol->display(); 
  
    // print top element of stack 
    cout << "\nTop element is " <<  sol->peek() << endl; 
  
    // delete top elements of stack 
    sol->pop(); 
    sol->pop(); 
  
    // display stack elements 
    sol->display(); 
  
    // print top element of stack 
    cout << "\nTop element is " << sol->peek() << endl; 

    return 0;
}