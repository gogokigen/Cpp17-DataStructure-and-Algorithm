/*******************************************************************
* https://leetcode.com/problems/reverse-words-in-a-string-ii/
* Medium
* 
* Conception: 
*  1. 
*
* Given an input string , reverse the string word by word. 
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
class Solution {
public:
    void reverseWords(vector<char>& s) {
        // reverse the whole string
        reverse(s.begin(), s.end());

        int len = s.size();
        int idx = 0;
        for (int start = 0; start < len; ++start) {
            if (s[start] != ' ') {
              // go to the beginning of the word
              if (idx != 0){
                  s[idx] = ' ';
                  idx++;
              }

              // go to the end of the word
              int end = start;
              while (end < len && s[end] != ' '){
                  s[idx] = s[end];
                  idx++;
                  end++;
              }

            // reverse the word
            reverse(s.begin() + idx - (end - start), s.begin() + idx);

            // move to the next word
            start = end;
          }
        }
      }
};