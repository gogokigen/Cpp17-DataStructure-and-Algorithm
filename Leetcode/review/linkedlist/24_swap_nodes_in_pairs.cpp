/*******************************************************************
* https://leetcode.com/problems/swap-nodes-in-pairs/
* Medium
*
* Given a linked list, swap every two adjacent nodes and return its head.
* You may not modify the values in the list's nodes. Only nodes itself may be changed.
*
* Example:
*
* Key:
*  1. 
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *first = head ;
        ListNode *second = first->next ;
        ListNode *prev = NULL ;

	    while(second != NULL ){
    	    if(first == head){
	   	        first->next = second->next ; 
	   	        second->next = first ; 
	   	        head = second ;
	        }else{
        	   	first->next = second->next ; 
	   	        second->next = first ; 
	   	        prev->next = second ; 
	        }
    	    prev = first ; 
	        first = first->next ; 
	        if(first == NULL){
        	   	return head ; 
	        }
	        second = first -> next ; 
	    }
        return head ;
    }
};
