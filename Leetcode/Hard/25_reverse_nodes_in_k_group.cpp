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
class Solution 
{
    // utility to get the length of the list
    static int get_length( ListNode* head ){
        auto length = 0;
        auto node = head;
        
        while( node != nullptr ){
            ++length;
            node = node->next;
        }
        return length;
    }
    
public:
    ListNode* reverseKGroup( ListNode* head, const int k) {
        // the resulting reversed list
        auto sentinel = new ListNode(0);
        auto new_node = sentinel;
        
        // get the length of the list so
        // we can keep track of when to stop
        // the reversal process
        auto index = 0, length = get_length( head );
        
        auto node = head;
        
        // while we have a reversal group remaining
        while( index + k <= length ){
            // save the current node as the new tail
            // so we can move the sentinel's pointer
            // up to the current location (this node
            // will be the last node in the reversed list)
            
            // ex 1 -> 2 > 3 --> 3 -> 2 -> 1
            ListNode* prev = nullptr, *new_tail = node;
            // standard list reversal process
            
            // save next, next = prev, prev = node
            for( auto pos = 0; pos < k; ++pos ){
                auto next = node->next;
                node->next = prev;

                prev = node;
                node = next;
            }
            
            // add the reversed group to the new list
            new_node->next = prev;
            // now the current sentinel node is pointing at the last
            // element in the list
            new_node = new_tail;
            index += k;
        }
        
        // no more groups left, so the tail will
        // just be the remaining elements of the original list
        if( node != nullptr )
            new_node-> next = node;
        
        return sentinel->next;
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
