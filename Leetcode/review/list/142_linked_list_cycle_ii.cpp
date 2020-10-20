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
        ListNode* fast = root->next;
        ListNode* slow = root;
        
        while(fast != slow){
            if(fast == NULL || fast->next == NULL){
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast == NULL || fast->next == NULL) return NULL;

        fast = fast->next;

        slow = root;
        while(slow != fast){
            fast = fast->next;
            slow = slow->next;
        }
  
        return fast;
    }
};
