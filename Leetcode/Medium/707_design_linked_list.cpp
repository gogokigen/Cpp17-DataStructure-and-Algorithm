/*******************************************************************
* https://leetcode.com/problems/design-linked-list/
* Medium
* 
* Conception: 
*  1. 
*
* Given a m x n grid filled with non-negative numbers,
* find a path from top left to bottom right
* which minimizes the sum of all numbers along its path.
*
* Example:
*
* Key:
*  1.
*
* Advanced:
*  1. 
*
*******************************************************************/

class Node {
public:
  int val;
  Node* next;
  Node(int x) {
      this->val = x;
      next = NULL;
  }
};

class MyLinkedList {
    int size;
    Node* head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size) return -1;

        Node* curr = head;
        int i = 0;
        while(curr){
            if(index == i){
                break;
            }
            curr = curr->next;
            i++;
        }
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

        Node* newNode= new Node(val);
        size++;

        if(head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        size++;

        if(head == NULL){
            head = newNode;
            return;
        }

        Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;

        Node* newNode = new Node(val);
        size++;

        if(index== 0){
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* curr = head;
        for (int i = 0; i < index - 1; i++){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size) return;
        if(index == 0){
            Node* tmp = head;
            head = head->next;
            delete tmp;
            size--;
            return;
        }

        Node *curr = head, *prev = NULL;
        for (int i = 0; i < index; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */