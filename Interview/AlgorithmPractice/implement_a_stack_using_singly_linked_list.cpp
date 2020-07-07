//https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
#include <iostream>

using namespace std;

// Declare linked list node 
  
struct Node { 
    int data; 
    struct Node* next; 
};


class Solution{
public:

struct Node* top; 
  
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
    temp->next = top; 
  
    // make temp as top of Stack 
    top = temp; 
} 
  
// Utility function to check if the stack is empty or not 
int isEmpty() { 
    return top == NULL; 
} 
  
// Utility function to return top element in a stack 
int peek() { 
    // check for empty stack 
    if (!isEmpty()) 
        return top->data; 
    else
        exit(1); 
} 
  
// Utility function to pop top  
// element from the stack 
  
void pop() { 
    struct Node* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        cout << "\nStack Underflow" << endl; 
        exit(1); 
    } 
    else { 
        // top assign into temp 
        temp = top; 
  
        // assign second node to top 
        top = top->next; 
  
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
    if (top == NULL) { 
        cout << "\nStack Underflow"; 
        exit(1); 
    } 
    else { 
        temp = top; 
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

    Solution* sol = new Solution;
    
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