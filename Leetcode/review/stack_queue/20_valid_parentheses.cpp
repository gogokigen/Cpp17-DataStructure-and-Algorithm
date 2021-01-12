/*******************************************************************
* https://leetcode.com/problems/valid-parentheses/
* Easy
* 
* Conception: 
*  1. stack
*
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
* determine if the input string is valid.
*
* An input string is valid if:
*
*    Open brackets must be closed by the same type of brackets.
*    Open brackets must be closed in the correct order.
*
* Note that an empty string is also considered valid.
*
*
* Example:
*
* Key:
*  1. 
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;

        stack<char> cache;
        for(auto c:s){
            if(c == '('){
                cache.push(c);
            }else if(c == ')'){
                if(!cache.empty()&&cache.top() == '('){
                    cache.pop();
                } else {
                    return false;
                }
            }
            
            if(c == '['){
                cache.push(c);
            }else if(c == ']'){
                if(!cache.empty()&&cache.top() == '['){
                    cache.pop();
                } else {
                    return false;
                }
            }
            
            if(c == '{'){
                cache.push(c);
            }else if(c == '}'){
                if(!cache.empty()&&cache.top() == '{'){
                    cache.pop();
                } else {
                    return false;
                }
            }
        }
        if(cache.empty()) return true;
        
        return false;
    }
};