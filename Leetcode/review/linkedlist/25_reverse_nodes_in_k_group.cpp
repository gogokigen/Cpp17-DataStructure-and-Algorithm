/*******************************************************************
* https://leetcode.com/problems/reverse-nodes-in-k-group/
* Hard
* 
* Conception: 
*  1. 
*
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* k is a positive integer and is less than or equal to the length of the linked list.
* If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
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
    int getLength( ListNode* head ){
        int length = 0;
        ListNode* node = head;
        
        while( node != nullptr ){
            ++length;
            node = node->next;
        }
        return length;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0), *start_pos = dummy;
        dummy->next = head;
        
        int index = 0, length = getLength( head );
        ListNode *curr = head;
        
        while( index + k <= length ){

            ListNode *node = curr, *prev = nullptr;
            for (int i = 0; i < k; i++) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            start_pos->next = prev;
            start_pos = node;
            index += k;

        }
        if( curr != nullptr ){
            start_pos->next = curr;
        }

        return dummy->next;
    }
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head)
			return head;
		if (k == 0 || k == 1)
			return head;

		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *pre = dummy;
		int len = 0;
		ListNode *let = head;
		while (let) {
			len++;
			let = let->next;
		}

		for (int i = 0; i < len / k; i++) {
			for (int j = 0; j < k - 1; j++) { // basically LL given is 1 based
				                              // and so we starting from 0 to =k-2 you may use 1 to =k-1
				ListNode *temp  = pre->next;
				pre->next = head->next;
				head->next = head->next->next;
				pre->next->next = temp;
			}
			pre = head;
			head = head->next;
		}
		ListNode *save = dummy->next;   
		delete(dummy);     /// TO AVOID  MEMORY LEAK
		return save;
	}
};
