/*******************************************************************
* https://leetcode.com/problems/letter-combinations-of-a-phone-number/
* Medium
* 
* Conception: 
*  1. 
*
* Given a string containing digits from 2-9 inclusive,
* return all possible letter combinations that the number could represent.
*
* A mapping of digit to letters (just like on the telephone buttons) is given below.
* Note that 1 does not map to any letters.
*
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
    vector<string> letterCombinations(string digits) {
        vector<string> tbl = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int len = digits.length();
        if (len == 0) return {};
        vector<string> ans;
        ans.push_back("");
        for(int i = 0; i < len; i++){
            char c = digits[i];
            while(ans[0].length() == i){
                string pop = ans[0];
                //cout << "pop: " << pop << endl;
                ans.erase(ans.begin() + 0);
                for(char v:tbl[c - '2']){
                    //cout << "pop + v: " << pop + v << endl; 
                    ans.push_back(pop + v);
                }
            }
        }
        return ans;
    }
};