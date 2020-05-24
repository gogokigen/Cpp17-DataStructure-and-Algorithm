/*******************************************************************
* Linked List from n to end
* 
* Conception: 
*  1. 
*
* Given a string, sort it in decreasing order based on the frequency of characters.
*
*
* Key:
*  1. 128 chars
*
* Explanation:
*
* References:
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
    Node* init;
    Node* returnKthToLast(Node* root, int k){
        if (root == NULL) return NULL;

        Node* curr = root;
        //if head is the target
        if(k == 0){
            root = curr->next;
            return root;
        }

        //k: start from 0 ..
        for(int i = 0; curr != NULL && i < k - 1; i++){
            curr = curr->next;
        }
        
        if(curr == NULL|| curr->next == NULL) return NULL;
        return curr;
    
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


    Solution* sol = new Solution;
    sol->init = sol->returnKthToLast(&node[0], 4);
    //1 2 3 4 5
    Node* tmp = sol->init;
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}