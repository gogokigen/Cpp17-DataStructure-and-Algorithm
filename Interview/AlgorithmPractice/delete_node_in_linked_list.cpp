/*******************************************************************
* 
* Practice: Delete a node in Linklist
* 
* References: 
*  1. By value https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
*  2. By position https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
*
* Key:
*  1. 
*
*******************************************************************/
#include <iostream>
using namespace std;

class Node {
public:
    Node() : val(0), next(nullptr) {}
    int val;
    Node* next = NULL;
};

class Solution {
public:
    Solution(){};

    void delete_by_value(Node* root, int val){
        if (root == NULL) return;

        Node* curr = root;
        Node* prev;
        
        //if head is the target
        while(curr != NULL && curr->val == val){
            root = curr->next;
            return;
        }
        
        while(curr != NULL && curr->val != val){
            prev = curr;
            curr = curr->next;
        }
        
        if(curr == NULL) return;
        prev->next = curr->next;
        //free(curr);
    }

    void delete_by_position(Node* root, int pos){
        if (root == NULL) return;

        Node* curr = root;
        //if head is the target
        if(pos == 0){
            root = curr->next;
            return;
        }

        //pos: start from 0 ..
        for(int i = 0; curr != NULL && i < pos - 1; i++){
            curr = curr->next;
        }
        
        if(curr == NULL|| curr->next == NULL) return;
    
        Node* tmp = curr->next->next;
        //free(curr->next);
        curr->next = tmp;
    }
};

int main()
{
// 1->2->3->4->5
    //Test Cases
    Node node[5];
    node[0].val = 1;
    node[0].next = &node[1];

    node[1].val = 2;
    node[1].next = &node[2];

    node[2].val = 3;
    node[2].next = &node[3];
    
    node[3].val = 4;
    node[3].next = &node[4];

    node[4].val = 5;
    node[4].next = NULL;


    Solution* sol = new Solution;
    sol->delete_by_value(&node[0], 4);
    //1 2 3 5
    sol->delete_by_position(&node[0], 2);
    //1 2 5
    Node* tmp = &node[0];
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}