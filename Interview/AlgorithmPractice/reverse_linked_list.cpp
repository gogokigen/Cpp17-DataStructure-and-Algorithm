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
class Solution {
public:
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