/*******************************************************************
* https://leetcode.com/problems/palindrome-partitioning/
* Medium
* 
* Conception: 
*  1. backtracking: https://www.geeksforgeeks.org/backtracking-introduction/
*
* Given a string s, partition s such that every substring of the partition is a palindrome.
* Return all possible palindrome partitioning of s.
*
* Example:
* Input: "aab"
* Output:
* [
*   ["aa","b"],
*   ["a","a","b"]
* ]
*
* Key:
*  1. 
*
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    Solution(){};
    vector<vector<string>> ret;
    string tmpS;
    
    bool isPalindrome(string sub){
        int start = 0;
        int end = sub.size() -1;
        
        while(start < end){
            if(sub[start] != sub[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void dfs(int idx, vector<string> partitedSub){
        if (idx == tmpS.size()){
            ret.push_back(partitedSub);
            return;
        }
        for (int i = idx ; i < tmpS.size(); i++){
            string sub = tmpS.substr(idx, i - idx + 1); //substr(init, length)
            if(isPalindrome(sub)){
                partitedSub.push_back(sub);
                dfs(i+1, partitedSub);
                partitedSub.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        tmpS = s;
        vector<string> partitedSub;
        dfs(0, partitedSub);
        
        return ret;
    }
};

int main()
{
    //Test Cases
    string s = "aab";// {{"aa","b"}, {"a","a","b"}}


    Solution* sol = new Solution;
    sol->ret = sol->partition(s);
    for(int i = 0; i < sol->ret.size(); i++){
        for(auto s : sol->ret[i]){
            cout << "result: " << s << endl;
        }
    }

    return 0;
}