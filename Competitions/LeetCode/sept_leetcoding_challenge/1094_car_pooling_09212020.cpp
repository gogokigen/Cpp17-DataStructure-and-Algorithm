/*******************************************************************
* https://leetcode.com/problems/car-pooling/
* Medium
* 
* Conception: 
*  1. 
*
* You are driving a vehicle that has capacity empty seats initially available for passengers.
* The vehicle only drives east (ie. it cannot turn around and drive west.)
*
* Given a list of trips, trip[i] = [num_passengers, start_location,
* end_location] contains information about the i-th trip: the number of passengers that must be picked up,
* and the locations to pick them up and drop them off.
* The locations are given as the number of kilometers due east from your vehicle's initial location.
*
* Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 
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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> timestamp(1001,0);

    for(auto trip : trips){
        timestamp[trip[1]] += trip[0];
        timestamp[trip[2]] -= trip[0];
    }

    int c=0;

    for(auto number : timestamp){
        c += number;
        if(c > capacity){
            return false;
        }
    }

    return true;
    }
};