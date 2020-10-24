/*******************************************************************
* https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
* Medium
* Conception: 
*
* In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.
* (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
*
* We may rotate the i-th domino, so that A[i] and B[i] swap values.
*
* Return the minimum number of rotations so that all the values in A are the same,
* or all the values in B are the same.
*
* If it cannot be done, return -1.
* 
* Example:
* 
*
* Key: "the same number is equal to eigher A[0] or B[0].
*       Doesn't try all numbers of two arrays."
*
*******************************************************************/
#include <iostream>
#include <vector> //for vector
using namespace std;


class Solution {
public:
    Solution(){};

    int check(int target, vector<int>& A, vector<int>& B, int length){
        int rotation_A = 0;
        int rotation_B = 0;
        
        for (int i = 0; i < length; i++){
            if (target != A[i] && target != B[i]) return -1;
            if (target != A[i]){
                rotation_A += 1;
            } else if (target != B[i]){
                rotation_B += 1;
            }
        }
        return min(rotation_A, rotation_B);
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        // thought:
        // "the same number is equal to eigher A[0] or B[0].
        //Doesn't try all numbers of two arrays."
        int length = A.size();
        int rotation = check(A[0],A,B, length);
        if ( -1 == rotation) {
            return check(B[0],A,B, length);
        }
        return rotation;
    }
};

int main()
{
    Solution* sol = new Solution;
    int ret;
    
    //Test Cases
    vector<int> A = {1,2,1,1,1,2,2,2};
    vector<int> B = {2,1,2,2,2,2,2,2}; // 1
    
    //A = [1,2,1,1,1,2,2,2], B = [2,1,2,2,2,2,2,2] //1
    //A = [2,1,2,4,2,2], B = [5,2,6,2,3,2] //2
    //A = [3,5,1,2,3], B = [3,6,3,3,4] //-1
    ret = sol->minDominoRotations(A , B); //true

    cout << ret << endl;

    return 0;
}