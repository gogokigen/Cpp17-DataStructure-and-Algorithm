/*******************************************************************
* https://leetcode.com/problems/linked-list-cycle/
* Easy
* 
* Conception: 
*  1. 
*
* Given a linked list, determine if it has a cycle in it.
*
* To represent a cycle in the given linked list,
* we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to.
* If pos is -1, then there is no cycle in the linked list.
*
*
* Key:
*  1. fast node >> slow
*
* Reference:
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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head->next; //twice faster than slow

        while(fast != slow){
            if(fast == NULL || fast->next == NULL){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};