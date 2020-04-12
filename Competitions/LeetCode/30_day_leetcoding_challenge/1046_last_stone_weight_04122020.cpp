/*******************************************************************
* https://leetcode.com/problems/last-stone-weight/
* Easy
* 
* Conception: 
*  1. 
*
* We have a collection of stones, each stone has a positive integer weight.
* Each turn, we choose the two heaviest stones and smash them together.
* Suppose the stones have weights x and y with x <= y.  The result of this smash is:
*
*    If x == y, both stones are totally destroyed;
*    If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
*
* At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
*
*
* Example:
*
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
    int lastStoneWeight(vector<int>& stones) {
        for(int i = stones.size() - 1; i > 0; i--){
            if(stones.size() == 1) return stones[0];
            sort(stones.begin(),stones.end());
            if(stones[i] != stones[i-1]){//stones[i] > stones[i-1]
                stones[i-1] = stones[i] - stones[i-1];
                stones.pop_back();
            }else{
                stones.pop_back();
                if (!stones.empty()) {
                  stones.pop_back();
                  --i;
                }
            }
            if(stones.size() == 0) return 0;
        }
        return stones[0];
    }
};