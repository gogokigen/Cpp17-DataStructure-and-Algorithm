/*******************************************************************
* https://leetcode.com/problems/valid-parentheses/
* Easy
* 
* Conception: 
*  1. stack
*
* Reference:
*  1. https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
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