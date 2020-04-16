/*******************************************************************
* https://leetcode.com/problems/valid-parenthesis-string/
* Medium
* 
* Conception: 
*  1. 
*
*  Given a string containing only three types of characters: '(', ')' and '*',
*  write a function to check whether this string is valid. We define the validity of a string by these rules:
*
*    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
*    Any right parenthesis ')' must have a corresponding left parenthesis '('.
*    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
*    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
*    An empty string is also valid.
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
    bool checkValidString(string s) {
        if(s.empty()) return true;

        stack<char> star;
        stack<char> cache;

        int pos = 0;
        for(auto c : s){
            if(c == '('){
                cache.push(pos);
            }else if(c == ')'){
                if(!cache.size() && !star.size()){
                    return false;
                }

                if(cache.size()){
                    cache.pop();
                }else{
                    star.pop();
                }
            }else{
                star.push(pos);
            }
            pos++;
        }
        
        if(cache.size() > star.size()){
            return false;
        }
        while(cache.size() && star.size()){
            if(star.top()<cache.top()){ //* can't be ')'
                return false;
            }
            cache.pop();
            star.pop();
        }

        return true;
        
    }
};