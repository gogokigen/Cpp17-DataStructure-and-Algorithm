/*******************************************************************
* Sum Two Linked Lists
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
    Node* sumTwoLinkedLists(Node* root1, Node* root2, int carry){
        if (root1 == NULL && root2 == NULL && carry == 0) return NULL;
        
        int value = carry;
        if(root1) value += root1->val;
        if(root2) value += root2->val;
        cout << value << endl;
        
        Node *res = new Node(value%10);
        res->next = sumTwoLinkedLists(root1 ? root1->next : NULL, root2 ? root2->next : NULL, value > 9 ? 1 : 0 );
        
        return res;
    
    }
};

int main(){
// 1->2->3
    //Test Cases
    Node node1[3];
    node1[0].val = 1;
    node1[0].next = &node1[1];

    node1[1].val = 2;
    node1[1].next = &node1[2];

    node1[2].val = 3;
    node1[2].next = NULL;

// 6->9->8->7
    Node node2[4];
    node2[0].val = 6;
    node2[0].next = &node2[1];

    node2[1].val = 9;
    node2[1].next = &node2[2];

    node2[2].val = 8;
    node2[2].next = &node2[3];
    
    node2[3].val = 7;
    node2[3].next = NULL;


    Solution* sol = new Solution;
    sol->init = sol->sumTwoLinkedLists(&node1[0], &node2[0], 0);
    //  8217 = 321 + 7896
    Node* tmp = sol->init;
    while(tmp != NULL){
        cout<<tmp->val;
        tmp = tmp->next;
    }

    return 0;
}
