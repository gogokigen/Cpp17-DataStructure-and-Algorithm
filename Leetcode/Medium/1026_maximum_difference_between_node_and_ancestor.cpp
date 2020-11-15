/*******************************************************************
* https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
* Medium
* 
* Conception: 
*  1. 
*
* Given the root of a binary tree,
* find the maximum value V for which there exist different nodes A and B
* where V = |A.val - B.val| and A is an ancestor of B.
*
* A node A is an ancestor of B if either: any child of A is equal to B,
* or any child of A is an ancestor of B.
*
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
    int maxAncestorMinusDescendant(TreeNode* root, int &result){
        if(!root)   return INT_MAX;
        if(!root -> left && !root -> right)     return root -> val;

        int leftMin = maxAncestorMinusDescendant(root -> left, result);
        int rightMin = maxAncestorMinusDescendant(root -> right, result);

        result = max(result, root -> val - min(leftMin, rightMin));
        return min({leftMin, rightMin, root -> val});
    }

    // this method finds the max diff value of (descendant - ancestor) in the entire tree and
    // keeps on updating the result when a higher diff value is found
    int maxDescendantMinusAncestor(TreeNode* root, int &result) {
        if(!root)   return INT_MIN;
        if(!root -> left && !root -> right)     return root -> val;

        int leftMax = maxDescendantMinusAncestor(root -> left, result);
        int rightMax = maxDescendantMinusAncestor(root -> right, result);

        result = max(result, max(leftMax, rightMax) - root -> val);
        return max({leftMax, rightMax, root -> val});
    }

    int maxAncestorDiff(TreeNode* root) {
        // since it is given that the tree will always contain >= 2 nodes and
        //we need to find thr abs value of |ancestor - descendant| the answer will always be +ve so we init it with the min possible value
        int result = 0;

        maxAncestorMinusDescendant(root, result);       // update result to highest (ancs - desc)
        maxDescendantMinusAncestor(root, result);       // update result to highest (desc - ancs)

        // return the higher of the 2 whenever the result got updated last
        //(this method of 2 separate function calls takes care of the V = |A.val - B.val| absolute value constraint given in the problem)
        return result;
    }
};