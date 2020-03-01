/*******************************************************************
* https://leetcode.com/problems/repeated-substring-pattern/
* Easy
* Conception: KMP algorithm
*             https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
*
* Given a non-empty string check
* if it can be constructed by taking a substring of it and 
* appending multiple copies of the substring together.
* You may assume the given string consists of lowercase English letters only and
* its length will not exceed 10000.
*
* 
* Example:
* Input: "abab"
* Output: True
* Explanation: It's the substring "ab" twice.
*******************************************************************/
#include <iostream>
using namespace std;


class Solution {
public:
    Solution(){};

    bool repeatedSubstringPattern_brute(string s) {
        int len = s.size();
        string tmp;
        for (int j = 1; j < len /2 + 1; j++){ // j partitions
            bool ret = true;
            tmp = s.substr(0, j);
            for (int k = 1; k < len / j + 1; k++){ // compare all substring
                if ( 0 == tmp.compare(s.substr(k*j, j)) || s.substr(k*j, j) == ""){
                    ret &=  true;
                } else {
                    ret &= false;
                    break;
                }
            }
            if ( ret == true) return ret;
        }
        return false;
    }
    
    //https://leetcode.com/problems/repeated-substring-pattern/discuss/299802/
    //Super-Simple-C%2B%2B-KMP-implementation-with-comments-T%3A-O(N)-S%3A-O(N)-Faster-than-95.67
    bool repeatedSubstringPattern(string s) {
       int F_ptr = 1;
       int B_ptr = 0;
       
       //The length of KMP array
       vector<int> KMP(s.size(),0);
       
       while (F_ptr < s.size()){
           if(s[F_ptr] == s[B_ptr]){
               // same char
               KMP[F_ptr] = B_ptr + 1;
               F_ptr++;
               B_ptr++;
           } else if (B_ptr != 0){
               // not equal
               B_ptr = KMP[B_ptr - 1];
           } else {
               F_ptr++;
           }
       }
       
       if (KMP[KMP.size() - 1] == 0){
           //every char is different.
           return false;
       }

       int last_substring = s.size() - KMP[KMP.size() - 1];
       
       if (0 == KMP[KMP.size() - 1]%last_substring){
           return true;
       }
       
       return false;
    }
};

int main()
{
    Solution* sol = new Solution;
    bool ret;
    
    //Test Cases
    //ret = sol->repeatedSubstringPattern("bb"); //true
    //ret = sol->repeatedSubstringPattern("a"); //false
    //ret = sol->repeatedSubstringPattern("aba"); //false
    ret = sol->repeatedSubstringPattern("ababab"); //true
    //ret = sol->repeatedSubstringPattern("abab"); //true
    //ret = sol->repeatedSubstringPattern("aabaaba"); //false
    //ret = sol->repeatedSubstringPattern("absde"); //false
    cout << ret << endl;

    return 0;
}