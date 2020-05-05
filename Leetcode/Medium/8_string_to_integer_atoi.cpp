/*******************************************************************
* https://leetcode.com/problems/string-to-integer-atoi/
* Medium
* 
* Conception: 
*  1. 
*
* Implement atoi which converts a string to an integer.
*
* Example:
*
* Notes:
*  1. Overflow
*  2. '+', '-', ' '
*
*
* Ref:
*  1. 
*
* Advanced:
*
*******************************************************************/
class Solution {
public:
    int myAtoi(string str) {
        if(str.length() == 0) return 0;
        long  ret = 0;
        int x = str.find_first_not_of(' ');
        if(x < 0) return 0;

        int sign = 1;
        if(str[x] == '-' || str[x] == '+'){
            sign = (str[x] =='+') ? 1 : -1;
            x++;
        }

        while(x < str.length()&& isdigit(str[x])){
            ret = ret*10 + (str[x++]-'0');
            if (ret * sign > INT_MAX) return INT_MAX;
            if (ret * sign < INT_MIN) return INT_MIN;
        }
        return sign * ret;
    }
};