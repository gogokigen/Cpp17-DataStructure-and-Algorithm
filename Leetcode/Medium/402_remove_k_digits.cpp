/*******************************************************************
* https://leetcode.com/problems/remove-k-digits/
* Medium
* 
* Conception: 
*  1. 
*
* Given a non-negative integer num represented as a string,
* remove k digits from the number so that the new number is the smallest possible.
*
* Note:
*    The length of num is less than 10002 and will be ≥ k.
*    The given num does not contain any leading zero.
*
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
    string removeKdigits(string num, int k) {
        string ret = "";
        int len = num.size();
        int remain = len - k;
        
        for(char o:num){
            while( k && ret.size() && ret.back()>o){
                //if left number > right number, remove left
                ret.pop_back();
                k--;
            }
            ret.push_back(o);
        }
        
        ret.resize(remain);
        
        while(!ret.empty() && ret[0] == '0'){
            ret.erase(ret.begin());
        }
        
        if(ret.empty()) return "0";
        
        return ret;
    }
};