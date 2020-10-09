/*******************************************************************
* https://leetcode.com/problems/largest-number/
* Medium
* 
* Conception: 
*  1. 
*
* Given a list of non-negative integers nums,
* arrange them such that they form the largest number.
*
* Note: The result may be very large, so you need to return a string instead of an integer.
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
/*
	Sorting + Comparison
	---------------------

	Q: Will only sorting work??(:
	A: No. :( why??
	
	Let's see.
	
	For example: 
	------------
	(Here we're sorting numbers based on their ASCII codes.)
	Lexicographically smaller comes first.
	
	example 1: 
	----------
	nums --> [3, 30]
	After sorting
	nums --> [3, 30]
	
	Formed number is [Left to Right] --> 330 (Which is our optimal answer)
	
	example 2:
	---------
	nums --> [4, 20]
	After sorting.
	nums --> [20, 4]
	
	Formed number is --> 204 (But this time it's not optimal ans.)
	
	Optimal ans is: 420
	
	-----------------------------------------------------
	
	So therefore, to find out the optimal answer we've to check
	every possible number that we can form using rest of the numbers
	after sorting.
	
	How the number will formed?
	---------------------------
	                  A      B
	first number --> "20" + "4" --> 204 (20 prefixed with others)
	second number ---> "4" + "20" --> 420 (20 suffixed with others)
	
	Here AB --> 204
		 BA --> 420
	
	So to from larger number --> B should comes before A in nums
	
	so therefore, we swaped their positions.
	
	***
	Similarly we've do in case our nums array has more
	than 2 elements.
	
	and finally our nums --> [4, 20]
	
	Append numbers of nums from Left to Right that 
	will be our optimal answer.
*/
class Solution {
public:
    static bool compare(int num1, int num2) {
        string a = to_string(num1);
        string b = to_string(num2);
        
        return (a + b) > (b + a);
    }
    
	string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string largestNumber = "";
        for(int i = 0; i < nums.size(); i += 1) {
            largestNumber += to_string(nums[i]);
        }
        
        return (largestNumber[0] == '0' ? "0" : largestNumber);
    }
};