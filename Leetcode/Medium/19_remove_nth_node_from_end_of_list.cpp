/*******************************************************************
* https://leetcode.com/problems/remove-nth-node-from-end-of-list/
* Medium
* 
* Conception: 
*  1. 
*
* Given a linked list, remove the n-th node from the end of list and return its head.
*
* Example:
* Given linked list: 1->2->3->4->5, and n = 2.
* After removing the second node from the end, the linked list becomes 1->2->3->5.
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

// Method 1: 1 pass
/* n =2                   X
 o ->  * - * - * - * - * - * - * -> NULL
dummy
 ^f  ..|...|...| =>| =>| =>| =>| =>+5
 ^s  =>| =>| =>| =>| =>+5
                      \______/^
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        for(int i = 1; i <= n + 1; i++){
            first = first->next;
        }
        while(first != NULL){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};


// Method 2: 2 pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = head;
        
        int length = 0;
        while(first != NULL){
            first = first->next;
            length++;
        }

        length = length - n;
        first = dummy;
        while(length > 0){
            first = first->next;
            length--;
        }
        ListNode* tmp = first->next; //avoid leak
        first->next = first->next->next;
        delete tmp; //avoid leak
        tmp = nullptr; //avoid leak
        return dummy->next;
    }
};