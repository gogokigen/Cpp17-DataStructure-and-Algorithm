/*******************************************************************
* https://leetcode.com/problems/plus-one/
* Easy
* 
* Conception: 
*  1. 
*
* Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
*
* The digits are stored such that the most significant digit is at the head of the list,
* and each element in the array contain a single digit.
*
* You may assume the integer does not contain any leading zero, except the number 0 itself.
*
*
* Example:
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
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size()==0){
            digits.push_back(1);
            return digits;
        }
        
        int len = digits.size();

        for(int i = len - 1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i] = digits[i] + 1;
                return digits;
            }
        }

        vector<int> ret;
        ret.push_back(1);
        ret.insert(ret.end(), digits.begin(), digits.end());
        return ret;
    }
};