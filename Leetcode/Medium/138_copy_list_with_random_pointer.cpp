/*******************************************************************
* https://leetcode.com/problems/copy-list-with-random-pointer/
* Medium
* 
* Conception: 
*  1. 
*
* A linked list is given such that each node contains an additional random pointer
* which could point to any node in the list or null.
* Return a deep copy of the list.
*
*
* Reference:
*  1. 
*
* Key:
*  1. 
*
*******************************************************************/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    map<Node*, Node*> visitedHash;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
          return nullptr;
        }
        if (visitedHash.count(head)) {
            return visitedHash[head];
        }
        Node* node = new Node(head->val);
        visitedHash[head] = node;

        // Recursively copy the remaining linked list starting once from the next pointer and then from
        // the random pointer.
        // Thus we have two independent recursive calls.
        // Finally we update the next and random pointers for the new node created.
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        
        return node;
    }
};