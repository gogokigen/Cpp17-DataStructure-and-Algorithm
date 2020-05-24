/*******************************************************************
* Linked List the kth from end
* 
* Conception: 
*  1. 
*
*
* Key:
*  1. 
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
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
    int val;
    Node* next = NULL;
};

 
class Solution {
public:
    Solution(){};
    Node* init;
    Node* returnTheKthNodefromLast(Node* root, int k){
        if (root == NULL) return NULL;
        if(k == 0){
            return root;
        }

        Node* dummy = root;
        //dummy->next = root;
        int length = 0;
        while(dummy != NULL){
            dummy = dummy->next;
            length++;
        }
        length = length - k;
        dummy = root;
        while(length > 0){
            dummy = dummy->next;
            length--;
        }

        return dummy;
    
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
    sol->init = sol->returnTheKthNodefromLast(&node[0], 4);
    //1 2 3 4 5
    Node* tmp = sol->init;
    // 2
    cout << sol->init->val << endl;


    return 0;
}