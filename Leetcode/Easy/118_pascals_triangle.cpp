/*******************************************************************
* https://leetcode.com/problems/pascals-triangle/
* Easy
* 
* Conception: 
*  1. 
*
* Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
*
* Example:
* 
* Explanation:
*  e.g. 5
*  curr = 1     ->                                                          -> r = [[1]]
*  curr = 1     ->                                         -> curr = 1,1    -> r = [ [1] , [1,1] ]
*  curr = 1,1   -> j = 2 - 1, curr[1] = curr[1] + curr[0]  -> curr = 1,2,1  -> r = [ [1] , [1,1] , [1,2,1] ]
*                                     = 1 + 1
*  curr = 1,2,1 -> j = 3 - 1, curr[2] = curr[2] + curr[1]  -> curr = 1,2,3
*                                     = 1 + 2
*               -> j = 1,     curr[1] = curr[1] + curr[0]  -> curr = 1,3,3  -> r = [ [1] , [1,1] , [1,2,1] , [1,3,3,1] ]
*                                     = 2 + 1
* References:
*  1. 
*
*******************************************************************/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;
        
        if  (numRows <= 0){
            return r;
        }
        
        vector<int> curr;
        curr.push_back(1);
        r.push_back(curr);
        for(int i = 0; i < numRows - 1; i++){
            for(int j = curr.size() - 1; j > 0; j--){
                curr[j] += curr[j-1];
            }
            curr.push_back(1);
            r.push_back(curr);
        }
        return r;
    }
};