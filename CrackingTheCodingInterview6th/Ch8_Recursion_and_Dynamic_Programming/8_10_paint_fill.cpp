/*******************************************************************
* https://leetcode.com/problems/flood-fill/
* Easy
* 
* Conception: 
*  1. 
*
* An image is represented by a 2-D array of integers,
* each integer representing the pixel value of the image (from 0 to 65535).
*
* Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill,
* and a pixel value newColor, "flood fill" the image.
*
* To perform a "flood fill", consider the starting pixel,
* plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel,
* plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel),
* and so on. Replace the color of all of the aforementioned pixels with the newColor. 
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
private:
    int row;
    int col;
    void helper(vector<vector<int>>& image, int x, int y, int oldColor, int newColor){
        if(x < 0 || x >= row || y < 0 || y >= col) return;
        
        if(image[x][y] != oldColor){
            return;
        }else{
            image[x][y] = newColor;
        }
        
        helper(image, x + 1, y, oldColor, newColor);
        helper(image, x - 1, y, oldColor, newColor);
        helper(image, x, y + 1, oldColor, newColor);
        helper(image, x, y - 1, oldColor, newColor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        
        row = image.size();
        col = image[0].size();
        helper(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};