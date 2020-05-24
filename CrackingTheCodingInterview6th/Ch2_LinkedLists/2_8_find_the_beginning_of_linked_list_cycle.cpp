/*******************************************************************
* Find the Beginning of Linked List Cycle
* https://leetcode.com/problems/linked-list-cycle-ii/
* Medium
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
    Node* findTheBeginningOfCycle(Node* root){
        if (root == NULL) return NULL;
        Node* fast = root;
        Node* slow = root;
        
        while(fast != NULL && fast->next != NULL ){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
            
            cout << "fast: " << fast->val << " ,slow: " << slow->val << endl;
        }
        
        if(fast == NULL || fast->next == NULL) return NULL;
        cout << "Find the same"<< endl;
        slow = root;
        while(slow != fast){
            cout << "fast: " << fast->val << " ,slow: " << slow->val << endl;
            slow = slow->next;
            fast = fast->next;
        }
  
        return fast;
    }
};

int main(){
// 1->2->3->4->5->2->3->4-> ..
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
    node[4].next = &node[1];

    Solution* sol = new Solution;
    sol->init = sol->findTheBeginningOfCycle(&node[0]);

    //2
    cout<<sol->init->val;

    return 0;
}