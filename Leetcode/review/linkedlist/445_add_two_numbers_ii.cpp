/*******************************************************************
* https://leetcode.com/problems/add-two-numbers-ii/
* Medium
* 
* Conception: 
*  1. 
*
* You are given two non-empty linked lists representing two non-negative integers.
* The most significant digit comes first and each of their nodes contain a single digit.
* Add the two numbers and return it as a linked list.
*
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
*
* Example:
* Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 8 -> 0 -> 7
*
*
* Similer: #2
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

// Method 1: reverse + #2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *head = NULL;
        int carry=0;
        while(l1 != NULL || l2 != NULL){
            int x = (l1 != NULL)?l1->val:0;
            int y = (l2 != NULL)?l2->val:0;
            int res = ( x + y + carry)%10;
            carry = ( x + y + carry)/10;
            ListNode *node = new ListNode(res);
            node->next = head;
            head = node;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        if(carry>0){
            ListNode *node = new ListNode(carry);
            node->next = head;
            head = node;
        }
        return head;
    }
    ListNode *reverse(ListNode *head){
        ListNode *prev = NULL,*next = NULL;
        while(head != NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

class Solution {
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* curr = head, *prev = nullptr, *next = nullptr;
        
        while(curr){
            //cout << curr->val << endl;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* curr = new ListNode(0);
        ListNode* head = curr;
        
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr){

            int total = 0;
            if(l1 != nullptr) total += l1->val;
            if(l2 != nullptr) total += l2->val;

            curr->next = new ListNode( (carry + total)%10);
            carry = (carry + total)/10;
            curr = curr->next;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }

        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        return reverseList(head->next);
    }
};


// Method 2:
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> nums1, nums2;
        while(l1) {
            nums1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            nums2.push_back(l2->val);
            l2 = l2->next;
        }

        int m = nums1.size(), n = nums2.size();
        int sum = 0, carry = 0;

        ListNode *head = nullptr, *t_next = nullptr;

        for(int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
            sum = carry;
            if(i >= 0) 
                sum += nums1[i];

            if(j >= 0)
                sum += nums2[j];

            carry = sum / 10;

            t_next = new ListNode(sum%10);
            t_next->next = head;
            head = t_next;
        }
        return head;
    }
};