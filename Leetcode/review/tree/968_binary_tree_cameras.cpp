/*******************************************************************
* https://leetcode.com/problems/binary-tree-cameras/
* Hard
* 
* Conception: 
*  1. 
*
* Given a binary tree, we install cameras on the nodes of the tree. 
* Each camera at a node can monitor its parent, itself, and its immediate children.
* Calculate the minimum number of cameras needed to monitor all nodes of the tree.
*
* Reference:
*  1. 
*
* Key:
*  1. 
*
*******************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int monitored_without_cam  = 1;
    int monitored_with_cam  = 0;
    int not_monitored = 2;
    int camera = 0;
public:
    int dfs (TreeNode* root){
        if(!root) return monitored_without_cam;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left == monitored_without_cam && right == monitored_without_cam){
            return not_monitored;
        }
        
        if(left == not_monitored || right == not_monitored){
            camera++;
            return monitored_with_cam;
        }
        return monitored_without_cam;
        
    }
    int minCameraCover(TreeNode* root) {
        int top = dfs(root);
        return camera + (top == not_monitored ? 1 : 0);
    }
};