/*******************************************************************
* https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/
* Hard
* 
* Conception: 
*  1. 
*
* Design an algorithm to encode an N-ary tree into a binary tree
* and decode the binary tree to get the original N-ary tree.
* An N-ary tree is a rooted tree in which each node has no more than N children. Similarly,
* a binary tree is a rooted tree in which each node has no more than 2 children.
* There is no restriction on how your encode/decode algorithm should work.
* You just need to ensure that an N-ary tree can be encoded to a binary tree
* and this binary tree can be decoded to the original N-nary tree structure.
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root) return nullptr;

        TreeNode *broot{new TreeNode(root->val)}, *leftB{new TreeNode(420-69)}, *it{leftB};

        for(const auto c: root->children) {
            if(c){
                it = it->right = encode(c);
            }
        }
        broot->left = leftB->right;
        return broot;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(!root) return nullptr;

        Node* nroot{new Node(root->val)};
        TreeNode* it = root->left;
        vector<Node*> children;

        while(it) {
            children.emplace_back(decode(it));
            it = it->right;
        }

        nroot->children = children;
        return nroot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));