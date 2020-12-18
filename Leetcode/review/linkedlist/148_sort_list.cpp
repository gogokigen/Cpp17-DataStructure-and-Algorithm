/*******************************************************************
* https://leetcode.com/problems/sort-list/
* Medium
* 
* Conception: 
*  1. 
*
* Sort a linked list in O(n log n) time using constant space complexity.
*
*
* Example:
*
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/problems/sort-list/discuss/689070/Merge-Sort-for-linked-lists-C%2B%2B
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
private:
    ListNode* mergeSort(ListNode* l1, ListNode* l2){
        ListNode* curr = new ListNode(-1);
        ListNode* real = curr;
        while( l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
            //cout << "curr: " << curr->val << endl;
        }
        if(l1 != NULL){
            curr->next = l1;
        }else {
            curr->next = l2;
        }
        return real->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        
        ListNode* l1 = sortList(head);
        //cout << "l1 head: " << head->val << " fast: " << fast->val << endl;
        ListNode* l2 = sortList(fast);
        //cout << "l2 head: " << head->val << " fast: " << fast->val << endl;
        return mergeSort(l1, l2);

    }
};