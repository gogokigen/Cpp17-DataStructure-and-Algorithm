/*******************************************************************
* https://leetcode.com/problems/house-robber-iii/
* Medium
* 
* Conception: 
*  1. 
*
* The thief has found himself a new place for his thievery again.
* There is only one entrance to this area, called the "root."
* Besides the root, each house has one and only one parent house.
* After a tour, the smart thief realized that "all houses in this place forms a binary tree".
* It will automatically contact the police if two directly-linked houses were broken into on the same night.
*
* Determine the maximum amount of money the thief can rob tonight without alerting the police.
*
*
* Example:
*
*
* Key:
*  1. Notice root! do not rob twice.
*
* Advanced:
*  1. 
*
*******************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void robTree(TreeNode *root , int& with_root, int& without_root){
        if (root == NULL){
            without_root = with_root = 0;
            return;
        }
        
        
        int with_left_root = 0;
        int with_right_root = 0;
        int without_left_root = 0;
        int without_right_root = 0;
        
        //       O <- root
        //     /   \
        //    o     o*
        //        
        robTree(root->right, with_right_root, without_right_root);

        //       O <- root
        //     /   \
        //    o*    o
        //        
        robTree(root->left, with_left_root, without_left_root);
 
        without_root = with_right_root + with_left_root; // root is not robbed, then robbing their children.
        with_root = max(root->val + without_right_root+ without_left_root, without_root);
                    // root is robbed, then do not rob their children.

    }


    int rob(TreeNode* root) {

        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        
        int without_root = 0;
        int with_root = 0;
        robTree(root , with_root, without_root);
        
        
        return with_root;
    }
};