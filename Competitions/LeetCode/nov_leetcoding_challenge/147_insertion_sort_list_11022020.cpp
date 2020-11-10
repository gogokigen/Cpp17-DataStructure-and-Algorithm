/*******************************************************************
* https://leetcode.com/problems/insertion-sort-list/
* Medium
* 
* Conception: 
*  1. 
*
* Sort a linked list using insertion sort.
*
*
* Example:
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head or !head->next)
            return head;
        
        ListNode* cur = head->next;
        ListNode* sortedHead = head;        
        sortedHead->next = NULL;
        
        while (cur) {
            ListNode* nextNode = cur->next;
            ListNode* sCur = sortedHead, *sPrev = NULL;
            
            while (sCur && sCur->val <= cur->val){
                sPrev = sCur;
                sCur = sCur->next;
            }
            if (!sPrev){
                cur->next = sortedHead, 
                sortedHead = cur;                
            } else {
                sPrev->next = cur,
                cur->next = sCur;
            }
            cur = nextNode;
        }
        
        return sortedHead;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head or !head->next)
            return head;

        ListNode *sortedHead = head;
        ListNode *curr = NULL;

        while (sortedHead) {
            curr = sortedHead->next;

            while (curr && sortedHead->val <= curr->val){
                sortedHead = sortedHead->next;
                curr = sortedHead->next;
            }
            
            // shift curr to tmp(start from head) position
            ListNode *tmp = head;
            while( curr && tmp && tmp != curr){
                if(tmp->val > curr->val){
                    int t_tmp = curr->val;
                    curr->val = tmp->val;
                    tmp->val = t_tmp;
                }
                tmp = tmp->next;
            }
            sortedHead = sortedHead->next;
        }
        
        return head;
    }
};