/*******************************************************************
* https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
* Easy
* 
* Conception: 
*  1. 
*
* Given head which is a reference node to a singly-linked list.
* The value of each node in the linked list is either 0 or 1.
* The linked list holds the binary representation of a number.
*
* Return the decimal value of the number in the linked list.
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
public:
    int getDecimalValue(ListNode* head) {
        string str = "";
        while(head!=nullptr){
            string temp = to_string(head->val);
            str += temp;
            head = head->next;
        }
        int ans = 0, c = str.size() - 1;
        for(auto x:str){
            if(x == '1')
                ans += pow(2,c);
            c--;
        }
        return ans;
    }
};