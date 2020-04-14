/*******************************************************************
* https://...
* Easy
* 
* Conception: 
*  1. 
*
* You are given a string s containing lowercase English letters,
* and a matrix shift, where shift[i] = [direction, amount]:
*    direction can be 0 (for left shift) or 1 (for right shift). 
*    amount is the amount by which string s is to be shifted.
*    A left shift by 1 means remove the first character of s and append it to the end.
*    Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
* Return the final string after all operations.
*
*
* Example:
*
* Key:
*  1. 
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:

//Method 1: Brute
    string stringShift(string s, vector<vector<int>>& shift) {
        for(int i = 0; i < shift.size(); i++){
            if(shift[i][0] == 1){
                int t = shift[i][1];
                int len = s.length();
                for(int j = 0; j < t; j++){
                    //forward
                    s = s.substr(len-1) + s.substr(0,len-1);
                }
            }
            if(shift[i][0] == 0){
                int t = shift[i][1];
                for(int j = 0; j < t; j++){
                    //backward
                    s = s.substr(1) + s[0];
                }
            }
        }
        return s;
    }

// Nethod 2: get total shift
string stringShift(string s, vector<vector<int>>& shift) {
        int left = 0, n = s.size();
        for(auto& it: shift) {
            if(it[0] == 0){
                left += it[1];
            }else{
                left -= it[1];
            }
        }
        
        if(left == 0){
            return s;
        }

        left %= n;
        if(left < 0){
            left += n;
        }
        
        return s.substr(left) + s.substr(0, left);
    }
};