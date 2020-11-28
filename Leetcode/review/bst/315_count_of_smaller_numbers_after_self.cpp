/*******************************************************************
* https://leetcode.com/problems/count-of-smaller-numbers-after-self/
* Hard
* 
* Conception: 
*  1. 
*
* You are given an integer array nums and you have to return a new counts array.
* The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
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
class Solution {
    struct TreeNode{
        int val;
        int sum;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x, int y) : val(x), sum(y), right(NULL), left(NULL){ }
    };
public:
    TreeNode* buildTree(TreeNode* root, int i, int num, int count, vector<int>& res){
        if(!root){
            TreeNode* root = new TreeNode( num, 1);
            res[i] = count;
            return root;
        }
        
        if(num > root->val){
            root->right = buildTree(root->right, i , num, count + root->sum, res);
        } else {
            root->sum++;
            root->left = buildTree(root->left, i, num, count, res);
        }
        return root;
    }
    /*
    void print(TreeNode* root){
        if(!root) return;
        print(root->left);
        
        cout << root->sum;
        
        print(root->right);
    }
*/
    vector<int> countSmaller(vector<int>& nums) {
        TreeNode* root = NULL;
        vector<int> res(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--){
            root = buildTree(root, i, nums[i], 0, res);
        }
        
        //print(root);
        return res;
    }
};