/*******************************************************************
* https://leetcode.com/problems/merge-k-sorted-lists/
* Hard
* 
* Conception: 
*  1. 
*
* You are given an array of k linked-lists lists,
* each linked-list is sorted in ascending order.
*
* Merge all the linked-lists into one sorted linked-list and return it.
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
    ListNode* mergeTwo(ListNode *left, ListNode *right){
        if(left == nullptr && right == nullptr) return NULL;
        if(left == nullptr && right != nullptr) return right;
        if(left != nullptr && right == nullptr) return left;
        
        ListNode* curr = new ListNode(0);
        ListNode* head = curr;
        while(left != nullptr && right!= nullptr){
            if(left->val >= right->val){
                curr->next = right;
                right = right->next;
            }else {
                curr->next = left;
                left = left->next;
            }
            curr = curr->next;
        }
        curr->next = left ? left:right;
        
        return head->next;
    }
    
    ListNode* merge(vector<ListNode*>& lists, int last){
        while(last != 0){
            int i = 0, j = last;
            while( i < j){
                lists[i] = mergeTwo(lists[i], lists[j]);
                i++;
                j--;
                
                if(i >= j){
                    last = j;
                    break;
                }
            }
        }
        return lists[0];
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
        return NULL;
        
        return merge(lists, lists.size()-1);
    }
};