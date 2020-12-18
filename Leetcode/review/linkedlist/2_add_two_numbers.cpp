/*******************************************************************
* https://leetcode.com/problems/add-two-numbers/
* Medium
* 
* Conception: 
*  1. dummy head
*
* You are given two non-empty linked lists representing two non-negative integers.
* The digits are stored in reverse order and each of their nodes contain a single digit.
* Add the two numbers and return it as a linked list.
*
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
*
* Example 1:
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* Explanation: 342 + 465 = 807.
*
* Example 2:
* [9,9,9,9,9,9,9]
* [9,9,9,9]
* Expected
* [8,9,9,9,0,0,0,1]
*
* Key:
*  1.
*
* References:
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
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* curr = new ListNode(0);
        ListNode* head = curr;
        
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr){
            int add = 0;
            if(l1 != nullptr) add += l1->val;
            if(l2 != nullptr) add += l2->val;
            
            curr->next = new ListNode((carry + add) % 10);
            curr = curr->next;

            carry = (carry + add) / 10;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }

        if(carry > 0) curr->next = new ListNode(carry);
        return head->next;
    }
};