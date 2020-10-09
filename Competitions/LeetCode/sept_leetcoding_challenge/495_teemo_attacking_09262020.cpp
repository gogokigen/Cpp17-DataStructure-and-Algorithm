/*******************************************************************
* https://leetcode.com/problems/teemo-attacking/
* Medium
* 
* Conception: 
*  1. 
*
* In LOL world, there is a hero called Teemo
* and his attacking can make his enemy Ashe be in poisoned condition.
* Now, given the Teemo's attacking ascending time series towards Ashe
* and the poisoning time duration per Teemo's attacking,
* you need to output the total time that Ashe is in poisoned condition.
*
* You may assume that Teemo attacks at the very beginning of a specific time point,
* and makes Ashe be in poisoned condition immediately.
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
	int findPoisonedDuration(vector<int>& timeseries, int duration) {
        if(timeseries.size()==0)  return 0;

        int count=0;

        for(int i=1;i<timeseries.size();i++){
            if(timeseries[i]-timeseries[i-1]>=duration){
                count+=duration;
            }else{
                count+=timeseries[i]-timeseries[i-1];
            }
        }
        count+=duration;
        return count;
    }
};