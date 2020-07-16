/*******************************************************************
* https://leetcode.com/problems/remove-linked-list-elements/
* Easy
* 
* Conception: 
*  1. 
*
* Remove all elements from a linked list of integers that have value val.
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
    // good
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        
        ListNode* curr = head;
         
        while (head && head->val == val){
            head = head->next;
            //delete(curr);
            curr = head;
        }
        ListNode* temp = curr;
        while (curr && curr->next){
            if (curr->next->val == val){
                temp = curr->next;
                curr->next = temp->next;
                //delete(temp);
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
    
    //Leak
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            if(curr->val == val){
                if(prev == NULL){
                    head = curr->next;
                }else{
                    prev->next = curr->next;
                }
            }else{
                prev = curr;
            }
            curr = curr->next;
        }

        return head;
    }
};