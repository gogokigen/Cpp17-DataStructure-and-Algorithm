/*******************************************************************
* https://leetcode.com/problems/remove-duplicate-letters/
* Medium
* 
* Conception: 
*  1. 
*
* Serialization is converting a data structure or object into a sequence of bits
* so that it can be stored in a file or memory buffer,
* or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
*
* Design an algorithm to serialize and deserialize a binary search tree.
* There is no restriction on how your serialization/deserialization algorithm should work.
* You need to ensure that a binary search tree can be serialized to a string,
* and this string can be deserialized to the original tree structure.
*
* The encoded string should be as compact as possible.
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1.
*
*******************************************************************/
// faster
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res="";
        int last[26] = {}, used[26] = {};
        int n = s.size();
        for(int i = 0; i < n; i++)
            last[s[i]-'a'] = i;
        for(int i = 0; i < n; i++){
            if(used[s[i]-'a']++ > 0)
                continue;
            while(!res.empty() && res.back() > s[i] && i < last[res.back()-'a']){
                used[res.back()-'a'] = 0;
                res.pop_back();
            }
            res.push_back(s[i]);
        }
        return res;
    }
};

//slower
class Solution {
public:
    string removeDuplicateLetters(string text) {
        int n = text.length();
        
        unordered_map<char, int> table;
        for (int i = 0; i < n; i++)
            table[text[i]]++;
        
        unordered_map<char, bool>seen;
        string res;
        
        for (int i = 0; i < n; i++) {
            cout << "i: " << i << endl;
            table[text[i]]--;
            if (seen[text[i]]) continue;
            seen[text[i]] = true;
            
            while(!res.empty() && res.back() > text[i] && table[res.back()] > 0) {
                seen[res.back()] = false;
                res.pop_back();
                //cout << "res.pop_back: " << res << endl;
            }

            res.push_back(text[i]);
            //cout << "res: " << res << endl;
        }
        
        return res;
    }
};
