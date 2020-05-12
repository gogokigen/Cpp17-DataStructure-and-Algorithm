/*******************************************************************
* https://leetcode.com/problems/palindrome-linked-list/
* Easy
* 
* Conception: 
*  1. 
*
* Given a singly linked list, determine if it is a palindrome.
*
* Key:
*  1. 
*
* Reference:
*  1. https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
*  2. https://zxi.mytechroad.com/blog/list/leetcode-234-palindrome-linked-list/
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
 //Stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        
        ListNode* dummy= head;
        stack<int> cache;
        while(dummy != NULL){
            cache.push(dummy->val);
            dummy = dummy->next;
        }
        
        while(head != NULL){
            int tmp = cache.top();
            cache.pop();
            
            if(tmp != head->val){
                return false;
            }else{
                head = head->next;
            }
        }

        return true;
        
    }
};

// Reverse
//            [1,2,2,5,3,2,1]
// 1st while:      ^s
// if (fast):        ^s
//  reverse :          ^s ...
// 2nd while:  ^head       ^s
//               ->       <-
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            //cout << "slow: " << slow->val << endl;
            fast = fast->next->next;
            slow = slow->next;

        }
        // if fast != nullptr, list has odd numbers
        if (fast) slow = slow->next;
        slow = reverse(slow);    
        while (slow) {
            //cout << "slow: " << slow->val << endl;
            //cout << "head: " << head->val << endl;
            if (slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
            
        }
        return true;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};