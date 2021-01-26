/*******************************************************************
* https://leetcode.com/problems/reverse-linked-list-ii/
* Medium
* 
* Conception: 
*  1. 
*
* Reverse a linked list from position m to n. Do it in one-pass.
* Note: 1 ≤ m ≤ n ≤ length of list.
*
*
* Key:
*  1. dummy node
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode *dummy = new ListNode(0), *prev = dummy;
        dummy->next = head;
        for (int i = 0; i < m - 1; i++) {
           prev = prev -> next;
        }

        ListNode *fast = prev->next, *tmp  = NULL;
        for (int i = 0; i < n - m; i++) {
            tmp = fast->next;
            fast->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
       }
        
        return dummy->next;
    }
};