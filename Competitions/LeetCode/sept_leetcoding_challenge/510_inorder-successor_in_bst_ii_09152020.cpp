/*******************************************************************
* https://leetcode.com/problems/inorder-successor-in-bst-ii/
* Medium
* 
* Conception: 
*  1. 
*
* Given a node in a binary search tree, find the in-order successor of that node in the BST.
* If that node has no in-order successor, return null.
* The successor of a node is the node with the smallest key greater than node.val.
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // the successor is somewhere lower in the right subtree
        if (node->right) {
            node = node->right;
            while (node->left) node = node->left;
            return node;   
        }
        
        // the successor is somewhere upper in the tree
        while (node->parent && node == node->parent->right) node = node->parent;
        return node->parent;
    }
};