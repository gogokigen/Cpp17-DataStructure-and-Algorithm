/*******************************************************************
* 
* Practice: Path with Sum
* 
* References: 
*  1. https://leetcode.com/problems/path-sum/
*  2. https://leetcode.com/problems/path-sum-ii/
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
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        
        sum -= root->val;
        if ((root->left == nullptr) && (root->right == nullptr))
          return (sum == 0);
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
        
    }
};



class Solution {
    vector<int> v;
    vector<vector<int>> ans;    
    void getSum( TreeNode *root , int target ){
        if( root == NULL )   return;
        
        int val = root->val;

        // If it is a leaf Node and value = target then Add the path  
        if( target == val && root->left == NULL  && root->right == NULL  ){
            v.push_back(val);      ans.push_back(v);
            v.pop_back();     // Remove the current Element for finding differnt paths 
        }

        // Push the element
        v.push_back(val);
        getSum( root->left , target-val);
        getSum( root->right , target-val);

        // If value Doesn't Count for Target Sum then Pop the last element
        v.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if( !root )
            return ans;
        getSum( root , sum );
        return ans;
    }
};