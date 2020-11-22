/*******************************************************************
* https://leetcode.com/problems/decode-string/
* Medium
* 
* Conception: 
*  1. 
*
* Given an encoded string, return its decoded string.
*
* Example:
*
*
* Key:
*  1. overflow
*
* References:
*  1. https://leetcode.com/problems/decode-string/discuss/87543/0ms-simple-C%2B%2B-solution
*  2. https://leetcode.com/problems/decode-string/discuss/87651/C%2B%2B-simple-and-clear-solution
*
*******************************************************************/
// ref 1.
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
    
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])){
                res += s[i];
                i++;
            } else {
                int n = 0;
                while (i < s.length() && isdigit(s[i])){
                    n = n * 10 + s[i] - '0';
                    i++;
                }
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0){
                    res += t;
                }
            }
        }
        
        return res;
    }
};

//ref. 2
class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string res;
        int num = 0;

        for(char c : s) {
            if(isdigit(c)) {
                num = num*10 + (c-'0');                              
            } else if(isalpha(c)) {
                res.push_back(c);                
            } else if(c == '[') {
                chars.push(res);
                nums.push(num);
                
                //reset
                res = "";
                num = 0;
            } else if(c == ']') {
                string tmp = res;
                for(int i = 0; i < nums.top()-1; ++i) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop();
                nums.pop();
            }
        }
        return res;
     }
};