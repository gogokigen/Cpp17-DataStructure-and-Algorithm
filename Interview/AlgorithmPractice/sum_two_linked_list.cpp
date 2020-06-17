/*******************************************************************
* Sum two linked list
* Easy
*
*
* (2 -> 4 -> 3) + (5 -> 6 -> 4)
* = 7->10->7
*
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) return nullptr;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* head = new ListNode(l1->val + l2->val);
        ListNode* root = head;
        while(l1->next != nullptr && l2->next != nullptr){
            l1 = l1->next;
            l2 = l2->next;
            head->next = new ListNode(l1->val + l2->val);
            head = head->next;
        }
        return root;
    }
};