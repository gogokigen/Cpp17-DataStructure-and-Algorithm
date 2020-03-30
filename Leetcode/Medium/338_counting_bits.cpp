/*******************************************************************
* https://leetcode.com/problems/counting-bits/
* Medium
* 
* Conception: 
*  1. 
*
* Given a non negative integer number num.
* For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation
* and return them as an array.
*
*
* Example:
* Input: 5
* Output: [0,1,1,2,1,2]
* Explanation: 0 =   0 -> 0
*              1 =   1 -> 1
*              2 =  10 -> 1
*              3 =  11 -> 2
*              4 = 100 -> 1
*              5 = 101 -> 2
* 
* Key:
*  1. 
*
* Advanced:
*  1. 
*
*******************************************************************/
#include <iostream>
#include <vector> //for vector
using namespace std;


class Solution {
public:
    Solution(){};

    vector<int> countBits(int num) {
        vector<int> ans(num + 1,0);

        if(num < 1) return ans;

        int base = 1;
        for(int i = 1; i < num+1; i++){
            if(i == base*2){
                base = base*2;
            }
            ans[i] = ans[i - base] + 1;
        }
        return ans;
    }
};

int main(){
    Solution* sol = new Solution;
    vector<int> ret;
    

    ret = sol->countBits(5);

    for(auto n : ret){
        cout << n << endl;
    }

    return 0;
}