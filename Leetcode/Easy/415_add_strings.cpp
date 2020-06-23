/*******************************************************************
* https://leetcode.com/problems/add-strings/
* Easy
* 
* Conception: 
*  1. 
*
* Given two non-negative integers num1 and num2 represented as string,
* return the sum of num1 and num2.
*
* Example:
*
*
* Key:
*  1. overflow
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1;
        int x = 0, y = 0, remainder = 0, carry = 0;
        string sum;
        while( i >= 0 || j>= 0){
            x = i >= 0 ? num1[i] - '0':0;
            y = j >= 0 ? num2[j] - '0':0;
            remainder = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            sum = (char)(remainder+ '0') + sum;
            i--;
            j--;
        }
        return carry == 1 ? "1"+sum:sum;
    }
};