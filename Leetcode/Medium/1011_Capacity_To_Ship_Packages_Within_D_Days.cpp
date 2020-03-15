/*******************************************************************
* https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
* Medium
* 
* Conception: 
*  1. binary search
*
* A conveyor belt has packages that must be shipped from one port to another within D days.
*
* The i-th package on the conveyor belt has a weight of weights[i].
* Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
* We may not load more weight than the maximum weight capacity of the ship.
*
* Return the least weight capacity of the ship 
* that will result in all the packages on the conveyor belt being shipped within D days.
*
*
* Example:
*
*
* Key:
*  1. iterater will be faster than recursion
*
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    Solution(){};

// Method 1
    int binarySearch(int lw, int rw, vector<int> weights, int D){
        
        if (lw == rw) return lw;
        int mid = lw + (rw - lw) / 2;
               
        int tmp = 0;
        int countDay = 0;

        for(int i = 0; i < weights.size(); i++){
            if(tmp + weights[i] <= mid){
                tmp = tmp + weights[i];
            } else {
                countDay++;
                i--;
                tmp = 0;
            }
                
            if (i == weights.size() - 1){
                if (countDay > D - 1){
                    mid = mid + 1 > rw ? mid : mid+1;
                    return binarySearch(mid, rw  , weights, D);
                } else if (countDay == D - 1){
                    return binarySearch(mid - 1, mid , weights, D);
                } else {
                    mid = mid - 1 <= lw ? mid : mid-1;
                    return binarySearch(lw, mid , weights, D);
                }
            }
        }
        return -1;
    }

    int shipWithinDays(vector<int>& weights, int D) {

        int lw = *max_element(weights.begin(), weights.end());
        int rw = 0;
        for(int i = 0; i < weights.size(); i++){
            rw = rw + weights[i];
        }

        int ret = 0; // max{weights} <= ret <= sum{i: weights}
        ret = binarySearch(lw , rw, weights, D);
        return ret;
    }
// Method 2
    // int findNumdays(vector<int> &weights, int mid) {
        // int numOfDays = 1;
        // int total = 0;
        // for(int i = 0; i < weights.size(); i++) {
            // total += weights[i];
            // if(total > mid) {
                // numOfDays += 1;
                // total = weights[i];
            // }
        // }
        // return numOfDays;
    // }
    
    // int shipWithinDays(vector<int>& weights, int D) {
        // int low = *max_element(weights.begin(), weights.end());
        // int high = 0;
        // for(auto i : weights) {
            // high += i;
        // }
        // while(low < high) {
            // int mid = low + (high - low)/2;
            // int numdays = findNumdays(weights, mid);
            // if(numdays <= D) {
                // high = mid;
            // } else {
                // low = mid+1;
            // }
        // }
        // return low;
    // }
};

int main()
{
    //Test Cases
    //vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    //int D = 5; //15
    //vector<int> weights = {3,2,2,4,1,4};
    //int D = 3; //6
    //vector<int> weights = {1,2,3,1,1};
    //int D = 4; //3
    //vector<int> weights = {10,50,100,100,50,100,100,100};
    //int D = 5; // 160

    Solution* sol = new Solution;
    int ret;
    ret = sol->shipWithinDays(weights ,D);

    cout << "result: " << ret << endl;

    return 0;
}