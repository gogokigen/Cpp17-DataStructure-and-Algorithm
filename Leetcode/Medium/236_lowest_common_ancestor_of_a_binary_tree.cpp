/*******************************************************************
* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
* Medium
* 
* Conception: 
*  1. 
*
* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
* According to the definition of LCA on Wikipedia:
* “The lowest common ancestor is defined between two nodes p and q as the lowest node in T
* that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/111548/my-C%2B%2B-solutions-with-explanation.-Both-recursive-and-iterative.
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
    TreeNode* ans;
    bool helper(TreeNode* curr, TreeNode* p, TreeNode* q){
        if(!curr) return false;
        
        int deep_left = helper(curr->left, p, q) ? 1 : 0;
        int deep_right = helper(curr->right, p, q) ? 1 : 0;
        
        //a node can be a descendant of itself 
        int mid = (curr == p) || (curr == q) ? 1 : 0;
        
        if( deep_left + deep_right + mid >= 2) {
            ans = curr;
        }

        return (mid + deep_left + deep_right > 0);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right) return root;
        return left == NULL ? right : left;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, TreeNode*> parent;
        stack<TreeNode*> stk;
        parent[root] = nullptr;
        stk.push(root);

        while (parent.find(p) == parent.end() || parent.find(q)==parent.end()) {
            TreeNode *node = stk.top();
            stk.pop();
            if (node->left != nullptr) {
                parent[node->left] = node;
                stk.push(node->left);
            }
            if (node->right != nullptr) {
                parent[node->right] = node;
                stk.push(node->right);
            }
        }

        set<TreeNode*> ancestors;
        while (p != NULL) {
            ancestors.insert(p);
            p = parent.find(p) != parent.end() ? parent[p] : nullptr;
        }
        
        while (ancestors.find(q) == ancestors.end()){
            q = parent.find(q)!=parent.end() ? parent[q] : nullptr;
        }
        return q;
    }
};