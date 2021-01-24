/*******************************************************************
* https://leetcode.com/problems/remove-duplicates-from-sorted-list/
* Easy
* 
* Conception: 
*  1. 
*
* Given the head of a sorted linked list,
* delete all duplicates such that each element appears only once.
* Return the linked list sorted as well.
*
*
* Key:
*  1.
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr){

            if( curr->val == curr->next->val){
                //remove curr
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};