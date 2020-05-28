/*******************************************************************
* Integer to Binary
* 
* Conception: 
*  1. 
*
* 
*
* Key:
*  1. 
*
* Reference:
*  1. https://www.geeksforgeeks.org/program-decimal-binary-conversion/
*
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    Solution(){};
    vector<int> countEach(int num){
        vector<int> result;
 
        while(num!=0){
            if(num%2==1){
                result.push_back(1);
            }else{
                result.push_back(0);
            }
            num = num/2;
        }
    reverse(result.begin(), result.end());
    return result;
    }
};

int main(){
    //Test Cases
    Solution* sol = new Solution;
    vector<int> result = sol->countEach(8);

    for(int i:result){
        cout<< i;
    }

    return 0;
}