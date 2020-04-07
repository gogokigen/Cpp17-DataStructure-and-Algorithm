/*******************************************************************
* //Counting Elements
* Medium
* 
* Conception: 
*  1. unordered_map
*
* Given an array of strings, group anagrams together.
*
*
* Example:
* Input: arr = [1,3,2,3,5,0]
* Output: 3
* Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
*
* Key:
*  1. 
*
* Advanced:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int countElements(vector<int>& arr) {
        vector<int> table(1001,0);
        for(int i = 0; i < arr.size(); i++){
            table[arr[i]] = table[arr[i]]+1;
        }
        int ret = 0;
        for(int i = 0; i < table.size()-1 ; i++){
            if(table[i+1] != 0){
                ret = ret + table[i];
            }
        }
        return ret;
    }

    int countElements(vector<int>& arr) {
        unordered_map<int, int> numFreq;

        for(auto num : arr){
            ++numFreq[num];
        }

        int count = 0;
        for(auto num : arr){
            if(numFreq.count(num + 1)){ //the number of the key = count(key)
                ++count;
                continue;
            }
        }
        return count;
    }
};