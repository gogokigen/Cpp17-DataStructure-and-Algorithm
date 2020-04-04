/*******************************************************************
* https://leetcode.com/problems/move-zeroes/
* Easy
* 
* Conception: 
*  1. swap
*
* Given an array nums,
* write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
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

    // Method 1: O(n)
    void moveZeroes(vector<int>& nums) {
        int nonzero_pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[nonzero_pos++], nums[i]);
            }
        }
    }

    // Method 2: fill
    void moveZeroes(vector<int>& nums) {
	     // Check in docs what actually STL remove do and fill the rest with zeroes
         fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
    }

    // Method 3: Brute
    void moveZeroes(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                continue;
            }else{
                int zero_ptr = i;
                // to find the nonzeroe num[j]
                for(int j = i + 1; j < nums.size(); j++){
                    if( nums[j] != 0){
                        // swap
                        int tmp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = tmp;
                        break;
                    }
                }
            }
        }
        
    }
};