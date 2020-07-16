/*******************************************************************
* 
* Practice: Insert a node in Linklist
* 
* References: 
*  1. 
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

    void add_in_position(Node* root, int value, int index){
        if (root == NULL) return;

        Node* curr = root;

        //pos: start from 0 ..
        for(int i = 0; curr != NULL && i < index - 1; i++){
            curr = curr->next;
        }
        
    
        Node* newNode = new Node();
        newNode->next = curr->next;
        newNode->val = value;
        curr->next = newNode;
    }
};

int main(){
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


    Solution* sol = new Solution();
    sol->add_in_position(&node[0], 999, 4);
    //1 2 3 4 999 5

    Node* tmp = &node[0];
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}