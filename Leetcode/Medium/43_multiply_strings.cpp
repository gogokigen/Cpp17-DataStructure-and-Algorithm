/*******************************************************************
* https://leetcode.com/problems/multiply-strings/
* Medium
* 
* Conception: 
*  1. 
*
* Given two non-negative integers num1 and num2 represented as strings,
* return the product of num1 and num2, also represented as a string.
*
* Example:
*
*
* Key:
*  1. 
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
public:
    string multiply(string num1, string num2) {
        if( num1 == "0" || num2 == "0") return "0";
        if( num1 == "1") return num2;
        if( num2 == "1") return num1;
        
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> ret(len1 + len2, 0);
        int pos = 0;
        
        
        // num1 = 123
        // num2 = 76
        // pos = 0:   3 * 76 <--- num2[t_pos] = 6, 7
        // pos = 1: + 2 * 76 <--- num2[t_pos] = 6, 7
        // pos = 2: + 1 * 76 <--- num2[t_pos] = 6, 7
        for(int i = len1 - 1; i >= 0; i--){
            int carry = 0;
            int t_pos = pos;
            for(int j = len2 - 1; j >= 0; j--){
                int sum = (num1[i] - '0') * (num2[j] - '0'); //integer
                int val = ret[t_pos] + sum + carry; 
                ret[t_pos] = (val) % 10;
                carry = val / 10;
                t_pos++;
            }
            ret[t_pos] = carry;
            pos++;
        }
        
        // find the ret[t_pos] != 0
        int t_pos = len1 + len2 - 1;
        while(t_pos >= 0 && ret[t_pos] == 0){
            t_pos--;
        }
        
        string retString;
        for(int i = t_pos; i >= 0; i--){
            retString.push_back(ret[i] + '0');
        }
        return retString.size() == 0 ? "0" : retString;
        
    }
};