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



// Method 2:
// https://leetcode.com/problems/add-two-numbers-ii/discuss/880961/C%2B%2B-No-reverse-Solution-Explained-~100-Time-~80-Space
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // support variables
        bool asRem = false;
        int pos1 = 0, pos2 = 0;
        ListNode *store1[100], *store2[100];
        // main loop to read
        while (l1 || l2) {
            // storing the explored values
            if (l1) {
                store1[pos1++] = l1;
                l1 = l1->next;
            }
            if (l2) {
                store2[pos2++] = l2;
                l2 = l2->next;
            }
        }
        // making sure l1 is not smaller
        if (pos1 < pos2) {
            swap(store1, store2);
            swap(pos1, pos2);
            //cout << store1[0]->val << ' ' << store2[0]->val << '\n';
            //cout << pos1 << ' ' << pos2 << '\n';
        }
        // main loop to write
        while (pos1--) {
            l1 = store1[pos1];
            l2 = pos2 > 0 ? store2[--pos2] : NULL;
            l1->val += asRem + (l2 ? l2->val : 0);
            asRem = l1->val > 9;
            l1->val %= 10;
        }
        // last touch: we need to add a node on top if we still had a remainder
        if (asRem) {
            l2 = new ListNode(1);
            l2->next = l1;
            l1 = l2;
        }
        return l1;
    }
};