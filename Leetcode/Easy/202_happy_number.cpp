/*******************************************************************
* https://leetcode.com/problems/happy-number/
* Easy
* 
* Conception: 
*  1. non-happy number will be a circle.
*
* Write an algorithm to determine if a number is "happy".
*
* A happy number is a number defined by the following process:
* Starting with any positive integer, replace the number by the sum of the squares of its digits,
* and repeat the process until the number equals 1 (where it will stay),
* or it loops endlessly in a cycle which does not include 1.
* Those numbers for which this process ends in 1 are happy numbers.
*
*
* Example:
* Input: 192
* Output: true
* Input: 116
* Output: false
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
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while (n != 1) {
            int sum = 0;
            while (n > 0) {
                sum += ((n % 10) * (n % 10));
                n /= 10;
            }
            n = sum;

            if (m.find(n) != m.end()){
                //circle
                break;
            } else {
                m[n] = 1;
            }
        }

        if (n == 1) return true;
        
        return false;
    }
};