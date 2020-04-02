/*******************************************************************
* https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
* Medium
* 
* Conception: 
*  1. dp and draw a binary tree bottom up
*
*
* Given an array arr of positive integers, consider all binary trees such that:
*
*   - Each node has either 0 or 2 children;
*   - The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
*     (Recall that a node is a leaf if and only if it has 0 children.)
*   - The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
*
* Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.
* It is guaranteed this sum fits into a 32-bit integer.
*
*
* Example:

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
    int mctFromLeafValues(vector<int>& arr) {
        if(arr.size() == 1) {
            return 0;
        }

        int sum = 0;
        while(arr.size() > 1){
            int min_product = INT_MAX;
            int ptr = 0;
            for(int i = 1; i < arr.size(); i++){
                if(min_product > arr[i - 1]*arr[i]){
                    min_product = arr[i - 1]*arr[i];
                    ptr = arr[i - 1] < arr[i] ? i-1 : i; //remove the smaller one
                }
            }
            sum = sum + min_product;
            arr.erase(arr.begin() + ptr);
        }
        return sum;
    }
};