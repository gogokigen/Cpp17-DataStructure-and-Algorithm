/*******************************************************************
* https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
* Medium
* 
* Conception: 
*  1. 
*
* Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
* Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
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
// Explanation:
// 1. First we will add all the numbers(in bit representation from MSB) to the trie.
// 2. Then for finding Maximum XOR, we need to find in the following way
// 3. We will start from the MSB(bit31,bit30,bit29,.....,bit0), and check whether there is path in trie with !bit31.
// 4. If yes we will follow path with !bit31, else will follow path with bit31.
// Example : (10000001) , if there is path in trie with (0,....) will follow that, else will follow (1......).
// 5. Iterate till bit0, and follow same steps above.
class Solution {
public:
    struct Trie{
        int val;
        Trie *nodes[2]={NULL};
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();
        Trie *prev;
		// This loop is to add each number from nums in trie.
        for( int i = 0 ; i < nums.size() ; i++ ){
            prev = root;
			// we starts with most significant digit.
            for( int j = 31 ; j >= 0 ; j--  ){
               int index = nums[i] & ( 1 << j);
               if( index != 0 )  index = 1;
               if( !prev->nodes[index] )  prev->nodes[index] = new Trie();
               prev = prev->nodes[index]; 
            }
            prev->val = nums[i];
        }
        int mx = 0;  
        for( int i = 0 ; i < nums.size() ; i++ ){
            prev = root;
            for( int j = 31 ; j >= 0 ; j--  ){
               int index = nums[i] & ( 1 << j);
			   // index represents child of root with bit value 0 or 1.
			   // Reversing index to check in trie, if index != 0 , then check with index 0 in trie, else check for opposite.
               if ( index != 0 ) index = 0;
               else index = 1; 
               if( prev -> nodes[index]) prev = prev->nodes[index];     
               else prev = prev->nodes[!index];                    
            }
            mx = max(mx,prev->val^nums[i]);
        }
        return mx;
    }
};