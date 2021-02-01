/*******************************************************************
* https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
* Medium
* 
* Conception: 
*  1. 
*
* Given a parentheses string s containing only the characters '(' and ')'.
* A parentheses string is balanced if:
*    Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
*    Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
*
* In other words, we treat '(' as openning parenthesis and '))' as closing parenthesis.
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
    int minInsertions(string s) {
        int len = s.length();
        stack<char> cache;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '('){
                cache.push(s[i]);
            }else {
                // If we have both )) in the string,
                //increment i and if we have a single ) increase count
                if (i + 1 < len && s[i] == s[i + 1]){
                    i++;
                }else{
                    ans++;
                }

                // If we have ( for corresponding )),
                //pop otherwise increase the count.
                if (!cache.empty()){
                    cache.pop();
                }else{
                    ans++;
                }
            }
        }
        
        return ans + cache.size() * 2;
    }
};
