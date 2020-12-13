/*******************************************************************
* https://leetcode.com/problems/basic-calculator-ii/
* Medium
* 
* Conception: 
*  1. Recursion
*
* Implement a basic calculator to evaluate a simple expression string.
* The expression string contains only non-negative integers, +, -, *, / operators and empty spaces.
* The integer division should truncate toward zero.
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
        stack<int> cache;
        int index = 0;
        long long int curr = 0, ans = 0;
        char lastOpertor = '+';
        while( index < len){
            char c = s[index];
            
            if(c >= '0' && c <= '9'){
                curr = curr*10 + c - '0';
            }
            if(c == '+' || c == '-' || c == '*' || c == '/' || index == len - 1){
                if(lastOpertor == '+'){
                    cache.push(curr);
                }else if (lastOpertor == '-'){
                    cache.push((-1) * curr);
                } else if(lastOpertor == '*'){
                    int tmp = cache.top();
                    cache.pop();
                    curr = curr * tmp;
                    cache.push(curr);
                }else if (lastOpertor == '/'){
                    int tmp = cache.top();
                    cache.pop();
                    curr = tmp / curr ;
                    cache.push(curr);
                }
                curr = 0;
                lastOpertor = c;
            }
            index++;
        }
        
        while(cache.empty() == false){
            ans = ans + cache.top();
            cache.pop();
        }
        return ans;
    }
};