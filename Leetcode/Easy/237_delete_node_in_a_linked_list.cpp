/*******************************************************************
* https://leetcode.com/problems/delete-node-in-a-linked-list/
* Easy
* 
* Conception: 
*  1. 
*
* Write a function to delete a node (except the tail) in a singly linked list,
* given only access to that node.
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next=node->next->next;
    }
};
