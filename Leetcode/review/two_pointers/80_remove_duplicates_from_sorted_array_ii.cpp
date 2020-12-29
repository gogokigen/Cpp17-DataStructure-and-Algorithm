/*******************************************************************
* https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
* Medium
* 
* Conception: 
*  1. 
*
* Given a sorted array nums, remove the duplicates in-place
* such that duplicates appeared at most twice and return the new length.
*
* Do not allocate extra space for another array;
* you must do this by modifying the input array in-place with O(1) extra memory.
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
    int removeDuplicates(vector<int>& nums) {
        //
        // Initialize the counter and the second pointer.
        //
        int j = 1, count = 1;
        
        //
        // Start from the second element of the array and process
        // elements one by one.
        //
        for (int i = 1; i < nums.size(); i++) {
            
            //
            // If the current element is a duplicate, increment the count.
            //
            if (nums[i] == nums[i - 1]) {
                
                count++;
                
            } else {
                
                //
                // Reset the count since we encountered a different element
                // than the previous one.
                //
                count = 1;
            }
            
            //
            // For a count <= 2, we copy the element over thus
            // overwriting the element at index "j" in the array
            //
            if (count <= 2) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
