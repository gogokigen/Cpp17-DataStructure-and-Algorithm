/*******************************************************************
* https://leetcode.com/problems/maximal-square/
* Medium
* 
* Conception: 
*  1. 2D vector: https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
*  2. dynamic programming
*
* Given a 2D binary matrix filled with 0's and 1's,
* find the largest square containing only 1's and return its area.
*
* Example:
*
*
* Key:
*  1. 
*
*******************************************************************/
#include <iostream>
#include <vector> //for vector
#include <algorithm> 
using namespace std;


class Solution {
public:
    Solution(){};
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = row > 0 ? matrix[0].size(): 0 ;
        vector<vector<int>> dp(row+1, vector<int>(col+1,0));
        int maxLength = 0;
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                if(matrix[i-1][j-1]== '1'){
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1])+1;
                    maxLength = max(maxLength,dp[i][j]);
                }
            }
        }
        return maxLength*maxLength;
    }
};

int main()
{
    //Test Cases
    vector<vector<char> > test{ { 0, 1, 1, 1, 0},
                               { 1, 1, 1, 1, 1},
                               { 0, 1, 1, 1, 1},
                               { 0, 1, 1, 1, 1},
                               { 0, 0, 1, 1, 1} };

    for (int i = 0; i < test.size(); i++) { 
        for (int j = 0; j < test[i].size(); j++){
            cout << static_cast<unsigned>(test[i][j]) << " ";
        }
        cout << endl; 
    } 

    Solution* sol = new Solution;
    int ret = 0;
    ret = sol->maximalSquare(test);

    cout << "result_head: " <<tmp->val<< endl;


    return 0;
}