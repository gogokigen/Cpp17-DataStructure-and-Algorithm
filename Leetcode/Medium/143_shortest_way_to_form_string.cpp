/*******************************************************************
* https://leetcode.com/problems/shortest-way-to-form-string/
* Medium
* 
* Conception: 
*  1.
*
* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
* reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
*
* Example:
*
*
* Refernces:
*  1. https://blog.techbridge.cc/2019/11/22/leetcode-pattern-fast-and-slow-pointer/
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
    ListNode* reverse(ListNode* head){
        ListNode *prev = nullptr;
        
        while(head != nullptr){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        // Find the middle of list
        ListNode *slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the list
        // l_0, l_1, l_2, l_3, l_4
        // second: l_4, l_3, l_2
        // fisrt: l_0, ... l_4
        ListNode *second = reverse(slow);
        ListNode *first = head;

        //e.d. first == l_0, second == l_n
        // Construct the new list by interleaving two lists
        while(first != nullptr && second != nullptr) {
            //tmp = l_1
            ListNode* tmp = first->next;
            // first->next = l_4
            first->next = second;
            
            
            // fisrt = l_1
            first = tmp;
            //tmp = l_3
            tmp = second->next;
            // second->next = l_1
            second->next = first;
            // second = l_3
            second = tmp;
        }
        if(first != NULL) first->next = NULL;
    }
};