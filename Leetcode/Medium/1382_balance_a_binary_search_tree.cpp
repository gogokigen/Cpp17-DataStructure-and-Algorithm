/*******************************************************************
* 
* Practice: Balance a Binary Search Tree
* https://leetcode.com/problems/balance-a-binary-search-tree/
*
* Given a binary search tree, return a balanced binary search tree with the same node values.
*
* A binary search tree is balanced if and only if 
* the depth of the two subtrees of every node never differ by more than 1.
*
*
* References: 
*  1. https://www.youtube.com/watch?v=vRwi_UcZGjU
*  2. https://gist.github.com/Harish-R/097688ac7f48bcbadfa5
*  3. Hua Hua https://www.youtube.com/watch?v=U24USYuOWzw
*  4. GeekFotGeek https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/
*
* Key:
*  1. BST: in-order is sorted.
*
* Advanced:
* AVL tree and its self-balancing
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
    //save inorder
    vector<int> cache;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        cache.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* buildTree(int l, int r){
        if(l > r) return nullptr;
        
        int m = l + (r - l) / 2;
        auto root = new TreeNode(cache[m]);
        root->left = buildTree(l, m -1);
        root->right = buildTree(m + 1, r);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildTree(0, cache.size() - 1);
    }
};