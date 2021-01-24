/*******************************************************************
* https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
* Medium
* 
* Conception: 
*  1. 
*
* Given the head of a sorted linked list,
* delete all nodes that have duplicate numbers,
* leaving only distinct numbers from the original list.
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
        
        ListNode* curr = new ListNode(0);
        curr->next = head;
        ListNode* pre = curr;
        while(head != nullptr){

            if( head->next && head->val == head->next->val){
                while (head->next&& head->val == head->next->val) {
                    head = head->next;    
                }
                pre->next = head->next;
            }else{
                pre = pre->next;
            }
            head = head->next;
        }
        return curr->next;
    }
};