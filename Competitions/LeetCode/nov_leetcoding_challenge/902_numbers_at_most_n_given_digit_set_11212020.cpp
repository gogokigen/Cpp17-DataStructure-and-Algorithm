/*******************************************************************
* https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
* Hard
* 
* Conception: 
*  1. 
*
* Given an array of digits, you can write numbers using each digits[i] as many times as we want. 
* For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
* Return the number of positive integers that can be generated that are less than or equal to a given integer n.
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
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        //Count number of possible numbers with 1 digit, 2 digit upto n-1 digit 
        // for last digit , try all possibilities which are lesser and equal to. 

        int m = digits.size() ; 
        int total = 0 ; 
        string nums = to_string(n) ; 
        int n_digits =nums.size() ; 

        for (int i = 1 ; i < n_digits ; i++ ){
            total += pow(m, i) ; 
        }        

        for (int i = 0 ; i < n_digits  ; i++){
            int lesser = 0 ; 
            int equal = 0 ; 
            for (auto & digit : digits){
                if (digit < nums.substr(i,1)){
                    lesser +=1 ; 
                } else if (digit == nums.substr(i,1)){
                    equal +=1 ; 
                }

            }

            int remaining = n_digits - i -1 ; 

            total += lesser*pow(m, remaining) ; 

            if (equal == 0) break ; 

            if( i == n_digits -1 and equal == 1 ){
                total +=1 ; 
            }
        }
        return total ; 
    }
};