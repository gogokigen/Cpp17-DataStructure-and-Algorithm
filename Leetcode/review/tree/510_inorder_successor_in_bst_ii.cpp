/*******************************************************************
* https://leetcode.com/problems/inorder-successor-in-bst-ii/
* Medium
* 
* Conception: 
*  1. 
*
* Given a binary search tree and a node in it,
* find the in-order successor of that node in the BST.
*
* The successor of a node p is the node with the smallest key greater
* than p.val.
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
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
            while (node->left){
                node = node->left;
            }
            return node;   
        }
        
        // the successor is somewhere upper in the tree
        while (node->parent && node == node->parent->right){
            node = node->parent;
        }

        return node->parent;
    }
};
