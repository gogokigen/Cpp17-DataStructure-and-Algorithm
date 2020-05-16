/*******************************************************************
* https://leetcode.com/problems/odd-even-linked-list/
* Medium
* 
* Conception: 
*  1. 
*
* Given a singly linked list, group all odd nodes together followed by the even nodes.
* Please note here we are talking about the node number and not the value in the nodes.
*
*
* Key:
*  1. 
*
* Reference:
*  1. https://www.geeksforgeeks.org/rearrange-a-linked-list-such-that-all-even-and-odd-positioned-nodes-are-together/
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
    ListNode* oddEvenList(ListNode* head) {
        if(head== NULL) return NULL;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        
        ListNode* evenHead = even;
        
        while(1){
            if(!odd||!even||!even->next){
                //final node
                odd->next = evenHead;
                break;
            }
            
            odd->next = even->next; //jump the even position
            odd = even->next;
            
            if (odd->next == NULL){
                //odd is the last one
                even->next = NULL;
                odd->next = evenHead;
                break;
            }
            
            even->next = odd->next;
            even = odd->next;
        }
        
        return head;
    }
};