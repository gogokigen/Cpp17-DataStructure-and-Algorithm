/*******************************************************************
* Sorted Array to BST
* 
* Conception: 
*  1. 
*
* 
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
    Solution(){};
    TreeNode* constructTree(vector<int>& array, int start, int end){

        if(start > end) return nullptr;
        int mid = (start + end)/2;  
        TreeNode* node = new TreeNode(array[mid]);

        node->left = constructTree(array, start, mid - 1);  
        node->right = constructTree(array, mid + 1, end);  
            
        return node;
    }
    void inOrder(TreeNode* node) {  
        if (node == NULL)  
            return;  
        inOrder(node->left);
        cout << node->val << " ";  
        inOrder(node->right);  
    }  
};

int main(){

    //Test Cases
    vector<int> arr = {0, 1, 2, 3, 5, 9};
    Solution* sol = new Solution;
    TreeNode* result = sol->constructTree(arr, 0 , arr.size() - 1);
    sol->inOrder(result);


    return 0;
}