/*******************************************************************
* https://leetcode.com/problems/valid-sudoku/
* Medium
* 
* Conception: 
*  1. 
*
* Determine if a 9x9 Sudoku board is valid.
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. https://leetcode.com/articles/valid-sudoku/#
*
*******************************************************************/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9 , vector<int> (9));
        vector<vector<int>> columns(9 , vector<int> (9));
        vector<vector<int>> boxes(9 , vector<int> (9));
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char num = board[i][j];
                if(num != '.'){
                    int n = num - '0';
                    n = n - 1;
                    int box_idx = i / 3 + (j / 3) * 3;
                    rows[i][n] += 1;
                    columns[j][n] += 1;
                    boxes[box_idx][n] += 1;
                    if(rows[i][n] > 1 || columns[j][n] > 1 || boxes[box_idx][n]> 1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};