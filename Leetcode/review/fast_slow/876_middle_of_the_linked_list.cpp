/*******************************************************************
* https://leetcode.com/problems/middle-of-the-linked-list/
* Easy
* 
* Conception: 
*  1. 
*
* Given a non-empty, singly linked list with head node head,
* return a middle node of linked list.
*
* If there are two middle nodes, return the second middle node.
*
*
* Example:
*
*
* Key:
*  1. 
*
* Advanced:
*  1. recursive version: https://www.geeksforgeeks.org/find-middle-singly-linked-list-recursively/
*
*******************************************************************/
//[1,2,3,4,5,6,7,8]
//head: 1
//fast: 3, slow: 2
//fast: 5, slow: 3
//fast: 7, slow: 4
//, slow: 5
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
    ListNode* middleNode(ListNode* head) {
        if(!head) return nullptr;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while( fast->next != nullptr&& fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
                                         //odd:even
        return (fast->next == nullptr) ? slow : slow->next;
    }
};
