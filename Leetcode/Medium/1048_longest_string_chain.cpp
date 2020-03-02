/*******************************************************************
* https://leetcode.com/problems/longest-string-chain/
* Medium
* 
* Conception: dynamic programming
* https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/586675/
*
* Let's say word1 is a predecessor of word2 if and only if
* we can add exactly one letter anywhere in word1 to make it equal to word2.
* For example, "abc" is a predecessor of "abac".
* A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1,
* where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.
* Return the longest possible length of a word chain with words chosen from the given list of words.
*
* Example:
* Input: ["a","b","ba","bca","bda","bdca"]
* Output: 4
* Explanation: one of the longest word chain is "a","ba","bda","bdca".
*
* Key:
*  1. unordered_map count() in C++
*     To count the number of elements present in an unordered_map with a given key.
*  2. C++ sort array of strings
*
*******************************************************************/
#include <iostream>
#include <vector> //for vector
#include <iterator> // iterator
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    Solution(){};
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(),
            [](string a, string b){
                return a.size() < b.size();
            }
        );
        
        // construct the map <the word, position>
        unordered_map<string, int> dict;
        for (int i = 0; i < words.size(); i++){
            dict[words[i]] = i;
        }
        
        // initial dp arrar for mark the subsequence indexs
        vector<int> dp(words.size(),1);
        int max_length = 0;
        for (int j = 0; j < words.size(); j++){
            string tmp_word = words[j]; 
            for (int k = 0; k < words[j].size(); k++){
                string check_word = tmp_word.substr(0,k) + tmp_word.substr(k+1);
                if(dict.count(check_word)){ // if check_word exists in dict
                    int z = dict[check_word]; // the position where check_word found
                    if (dp[j] < dp[z] +1){
                        dp[j] = dp[z] + 1;
                    }
                }
            }
            max_length = max(max_length, dp[j]);
        }
        return max_length;
    }
};

int main()
{
    Solution* sol = new Solution;
    int ret;
    
    //Test Cases
    vector<string> test = {"a","b","ba","bca","bda","bdca"}; //4

    ret = sol->longestStrChain(test);
    cout << ret << endl;

    return 0;
}