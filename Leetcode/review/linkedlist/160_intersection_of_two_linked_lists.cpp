/*******************************************************************
* https://leetcode.com/problems/intersection-of-two-linked-lists/
* Easy
* 
* Conception: 
*  1. 
*
* Write a program to find the node at 
* which the intersection of two singly linked lists begins.
*
*
* Explanation:
*
* Key:
*  1. 
*
* Advanced:
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* r_headA = headA;
        ListNode* r_headB = headB;
        while(r_headA != r_headB){
            r_headA = r_headA!=NULL ? r_headA->next:headB;
            r_headB = r_headB!=NULL ? r_headB->next:headA;
        }
        return (r_headA==r_headB && r_headA != NULL) ? r_headA : NULL; 
    }
};