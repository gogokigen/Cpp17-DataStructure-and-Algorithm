/*******************************************************************
* https://leetcode.com/problems/basic-calculator/
* Hard
* 
* Conception: 
*  1. Stack
*
* Implement a basic calculator to evaluate a simple expression string.
* The expression string may contain open ( and closing parentheses ),
* the plus + or minus sign -, non-negative integers and empty spaces .
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        stack<int> nums, ops;
        int index = 0, sign = 1, ans = 0;
        long long int curr = 0;
        char lastOpertor = '+';
        while( index < len){
            char c = s[index];
            
            if(c >= '0' && c <= '9'){
                curr = curr*10 + c - '0';
            }
               
            if(c == '+' || c == '-' || c == '(' || c == ')' || index == len - 1){
                ans += sign * curr;
                curr = 0;
                if(c == '+'){
                    sign = 1;
                }else if (c == '-'){
                    sign = -1;
                } else if(c == '('){
                    nums.push(ans);
                    ops.push(sign);
                    ans = 0;
                    sign = 1;
                }else if (c == ')' && ops.size()){
                    ans = ops.top() * ans + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }
            index++;
        }
        ans += sign * curr;

        return ans;
    }
};