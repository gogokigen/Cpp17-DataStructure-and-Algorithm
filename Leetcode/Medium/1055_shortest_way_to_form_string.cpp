/*******************************************************************
* https://leetcode.com/problems/shortest-way-to-form-string/
* Medium
* 
* Conception: 
*  1. DP is fine.
*
* From any string, we can form a subsequence of that 
* string by deleting some number of characters (possibly no deletions).
*
* Given two strings source and target, return the minimum number of subsequences of source 
* such that their concatenation equals target.
* If the task is impossible, return -1.
*
*
* Example:
*
*
* Key:
*  1. 
*
*******************************************************************/
#include <iostream>
using namespace std;


class Solution {
public:
    Solution(){};

    int shortestWay(string source, string target) {
        int ret = 0;
        int t_i = 0;
        while(t_i < target.size()){
            int checkTarget = t_i; 
            for(int s_i = 0; s_i < source.size(); s_i++){
                if(source[s_i] != target[t_i]){
                    continue;
                } else {
                    t_i++;
                }
            }
            
            //"checkTarget" fixed means no any source[s_i] match
            if(checkTarget == t_i) return -1;
            
            ret++;
        }
        return ret;
    }
};

int main()
{
    //Test Cases
    string source = "xyz", target = "xzyxz"; //3
    //string source = "abc", target = "abcbc"; //2
    //string source = "abc", target = "acdbc"; //-1



    Solution* sol = new Solution;
    int ret;
    ret = sol->shortestWay(source ,target);

    cout << "result: " << ret << endl;

    return 0;
}