/*******************************************************************
* https://leetcode.com/problems/confusing-number/
* Easy
* 
* Conception: 
*  1.
*
* Given a number N, return true if and only if it is a confusing number,
* which satisfies the following condition:
*
* We can rotate digits by 180 degrees to form new digits.
* When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively.
* When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid.
* A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.
*
*
* Example:
*
*
* Key:
*  1. 
*
*******************************************************************/
class Solution {
public:
    bool confusingNumber(int N) {
        unordered_map <int,int> table = {{0,0},{1,1},{6,9},{8,8},{9,6}};

        
        int init = N;
        int result = 0;
        
        while( init != 0){
            int digit = init % 10;
            
            if (!table.count(digit)) {
            	return false;
            }
            
            result = result * 10 + table[digit];
            init = init / 10;
        }

        return N!= result;
    }
};