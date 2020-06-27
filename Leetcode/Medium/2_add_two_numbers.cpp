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
* Example:
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* Explanation: 342 + 465 = 807.
*
* Key:
*  1.
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

        ListNode* dummy = new ListNode(0);
        ListNode* root = dummy, *p = l1, *q = l2;
        int addition = 0;
        while(p != nullptr || q != nullptr){
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int tmp = addition + x + y;
            addition = tmp/10;
            
            root->next = new ListNode(tmp%10);
            
            root = root->next;
            //cout << "dummy->next: " << dummy->next->val << endl;
            //cout << "root->next: " << root->val << endl;
    
            if(p != nullptr) p = p->next;
            if(q != nullptr) q = q->next;
        }

        if(addition > 0) root->next = new ListNode(addition);
        return dummy->next;
    }
};