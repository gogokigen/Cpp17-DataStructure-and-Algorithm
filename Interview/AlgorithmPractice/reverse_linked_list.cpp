/*******************************************************************
* https://leetcode.com/problems/reverse-linked-list/
* Easy
* 
* Conception: 
*  1. https://www.geeksforgeeks.org/reverse-a-linked-list/
*
* Reverse a singly linked list.
*
*
* Explanation:
* 
* Step 0: ListNode* prev = NULL;
*         ListNode* next = NULL;
*         ListNode* curr = head;
* 
*           curr head
*              v v
*    NULL      "1" -> "2" -> "3" -> NULL
* prev^ ^next
*
*
* Step 1: next = curr->next;
* 
*           curr head
*              v v
*    NULL      "1" -> "2" -> "3" -> NULL
* prev^                ^next
*
*
* Step 2: curr->next = prev;
* 
*           curr head
*              v v
*    NULL  <-- "1"    "2" -> "3" -> NULL
* prev^                ^next
*
*
* Step 3: prev = curr;
*         curr = next;
* 
*                head  curr
*                v     v
*    NULL  <-- "1"    "2" -> "3" -> NULL
*           prev^      ^next
*
*
* Key:
*  1. 
*
* Advanced:
*  1. https://stackoverflow.com/questions/2434411/linked-list-recursive-reverse
*  2. https://www.geeksforgeeks.org/data-structures-linked-list-question-5/
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
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* init;
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev; //really revere
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    
    

    void recursiveReverse(struct ListNode** head_ref){
        struct ListNode* current;
        struct ListNode* prev;

        /* empty list */
        if (*head_ref == NULL)
           return;  

        /* suppose current = {1, 2, 3}, prev = {2, 3} */
        current = *head_ref;
        prev  = current->next;

        /* List has only one node */
        if (prev == NULL)
           return;  

        /* put the current element on the end of the list */
        recursiveReverse(&prev);
        current->next->next  = current; 

        /* tricky step -- see the diagram */
        current->next  = NULL;         

        /* fix the head pointer */
        *head_ref = prev;
    }
    
    void reverse(struct ListNode** head_ref) { 
        struct ListNode* prev   = NULL; 
        struct ListNode* current = *head_ref; 
        struct ListNode* next; 
        while (current != NULL) { 
            next  = current->next;   
            current->next = prev;    
            prev = current; 
            current = next; 
        }
        *head_ref = prev;
    }

};


int main(){
// 1->2->3->4->5
    //Test Cases
    ListNode node[5];
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
    sol->init = sol->reverseList(&node[0]);
    
    while(sol->init != NULL ){
        cout << sol->init->val << endl;
        sol->init = sol->init->next;
    }


    return 0;
}