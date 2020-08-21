/*******************************************************************
* 
* Practice: List of Depths
* 
* References: 
*  1. https://ianna1009.gitbooks.io/leectcode/content/Cracking%20Coding%20Interview/Chapter4.%20Trees%20and%20Graph/list_of_depths.html
*  2. https://leetcode.com/problems/binary-tree-level-order-traversal/
*
* Key:
*  1. BFS
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> q;

        if(root) q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            while(n--){
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            levels.push_back(level);
        }
        return levels;
    }
};