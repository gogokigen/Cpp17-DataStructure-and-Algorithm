/*******************************************************************
* https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
* Medium
* 
* Conception: 
*  1. 
*
* Given a node from a Circular Linked List which is sorted in ascending order,
* write a function to insert a value insertVal into the list such that it remains a sorted circular list.
* The given node can be a reference to any single node in the list,
* and may not be necessarily the smallest value in the circular list.
*
* If there are multiple suitable places for insertion,
* you may choose any place to insert the new value.
* After the insertion, the circular list should remain sorted.
*
* If the list is empty (i.e., given node is null),
* you should create a new single circular list and return the reference to that single node.
* Otherwise, you should return the original given node.
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node *prev = head;
        Node *next = head->next;
        bool inserted = false;
        while(true) {
            if ((prev->val <= insertVal && next->val >= insertVal) ||
                (prev->val > next->val && insertVal < next->val) ||          
                (prev->val > next->val && insertVal > prev->val)) {
                    prev->next = new Node(insertVal, next);
                    inserted = true;
                    break;
                }
            prev = prev->next;
            next = next->next;
            if (prev == head) break;
        }       
        if (!inserted) {
            prev->next = new Node(insertVal, next);
        } 
        return head; 
    }
};