/*******************************************************************
* https://leetcode.com/problems/...
* Medium
* 
* Conception: 
*  1. 
*
* There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
*
* You have to form a team of 3 soldiers amongst them under the following rules:
* Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
* A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
*
* Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
*
*
* Example:
* Input: rating = [2,5,3,4,1]
* Output: 3
* Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
*
*
* Key:
*  1. Since House[1] and House[n] are adjacent, they cannot be robbed together.
*     Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], 
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:

    //method 1: force method
    int numTeams(vector<int>& rating) {
        int len = rating.size();
        vector<vector<int>> lists;
        int count = 0;
        
        int st, nd, rd = 0;
        for(int i = 0; i < rating.size(); i++){
            st = rating[i];
            for(int j = i + 1; j < rating.size(); j++){
                if(st <= rating[j]){
                    nd = rating[j];
                    for(int k = j + 1; k < rating.size(); k++){
                        if(nd <= rating[k]){
                            rd = rating[k];
                            lists.push_back({st,nd,rd});
                        }
                    }
                } else {
                    nd = rating[j];
                    for(int k = j + 1; k < rating.size(); k++){
                        if(nd > rating[k]){
                            rd = rating[k];
                            lists.push_back({st,nd,rd});
                        }
                    }
                }
            }
        }
        return lists.size();
    }
    
    //method 2
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for(int i = 0; i < rating.size(); i++){
            int lSmall = 0, rLarge= 0, lLarge= 0, rSmall = 0;
            for(int j = 0; j < i; j++){
                if(rating[j] < rating[i]){
                    lSmall++;
                } else {
                    lLarge++;
                }
            }
            for(int j = i+1; j < rating.size(); j++){
                if(rating[j] < rating[i]){
                    rSmall++;
                } else {
                    rLarge++;
                }
            }
            ans+= lSmall * rLarge + lLarge * rSmall;
        }
        return ans;
    }
};