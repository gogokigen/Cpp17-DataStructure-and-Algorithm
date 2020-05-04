/*******************************************************************
* https://leetcode.com/problems/number-complement/
* https://leetcode.com/problems/complement-of-base-10-integer/
* Easy
* 
* Conception: 
*  1. 
*
* Given a positive integer, output its complement number.
* The complement strategy is to flip the bits of its binary representation.
*
* Example:
*
* Ref:
*  1. 
*
* Advanced:
*
*******************************************************************/
class Solution {
public:
    int findComplement(int num) {
        int idx = (int)log2(num) +1;
        return pow(2,idx) - num -1;
    }
};