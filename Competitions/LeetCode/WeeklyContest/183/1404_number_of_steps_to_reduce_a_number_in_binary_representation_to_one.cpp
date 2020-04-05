/*******************************************************************
* https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
* Medium
* 
* Conception: 
*  1. bitset
*  2. 
*
* Given a number s in their binary representation.
* Return the number of steps to reduce it to 1 under the following rules:
*
*   If the current number is even, you have to divide it by 2.
*   If the current number is odd, you have to add 1 to it.
*
* It's guaranteed that you can always reach to one for all testcases.
*
*
* Example:

* 
* Key:
*  1. https://www.geeksforgeeks.org/c-bitset-interesting-facts/
*     https://www.geeksforgeeks.org/c-bitset-and-its-application/
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    using bit=bitset<505>;
    bit add(const bit&a, const bit&b){
        return b.count()==0?a:add(a^b,(a&b)<<1);
    }

    int numSteps(string s) {
        bit source(s), one(1);
        int count = 0;
        while(source!=one){
            if(s[s.size() - 1] - '0' == 1){
                source = add(source, one);
            } else {
                source = source >> 1;
            }
            //cout <<source << endl;
            s = source.to_string();
            count++;
        }
        return count;
    }
};