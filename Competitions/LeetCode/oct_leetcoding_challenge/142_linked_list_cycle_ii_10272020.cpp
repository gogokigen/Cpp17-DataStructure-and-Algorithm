/*******************************************************************
* https://leetcode.com/problems/linked-list-cycle-ii/
* Medium
* 
* Conception: 
*  1. 
*
* Given a linked list, return the node where the cycle begins.
* If there is no cycle, return null.
*
* There is a cycle in a linked list
* if there is some node in the list that can be reached again by continuously following the next pointer.
* Internally, pos is used to denote the index of the node that
* tail's next pointer is connected to.
*
* Note that pos is not passed as a parameter.
* Notice that you should not modify the linked list.
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* root){
        if (root == NULL) return NULL;
        ListNode* fast = root;
        ListNode* slow = root;
        
        while(fast != NULL && fast->next != NULL ){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                //cout << "!fast: " << fast->val << " ,slow: " << slow->val << endl;
                break;
            }
            //cout << "fast: " << fast->val << " ,slow: " << slow->val << endl;
        }
        
        if(fast == NULL || fast->next == NULL) return NULL;
        //cout << "Find the same"<< endl;
        slow = root;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
            //cout << "fast: " << fast->val << " ,slow: " << slow->val << endl;
        }
  
        return fast;
    }
};


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
