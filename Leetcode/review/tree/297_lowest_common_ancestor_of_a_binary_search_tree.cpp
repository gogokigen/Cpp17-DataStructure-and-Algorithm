/*******************************************************************
* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
* Hard
* 
* Conception: 
*  1. 
*
* Serialization is the process of converting a data structure or object into a sequence of bits
* so that it can be stored in a file or memory buffer,
* or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
*
* Design an algorithm to serialize and deserialize a binary tree.
* There is no restriction on how your serialization/deserialization algorithm should work.
* You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original 
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        
        return to_string(root->val) + "," +  serialize(root->left) + "," +  serialize(root->right);
    }

    TreeNode* helper(queue<string>& q){
        
        string root_val = q.front();
        q.pop();
        if(root_val == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(root_val));
        root->left = helper(q);
        root->right = helper(q);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        queue<string> q;
        string s;
        for(char c:data){
            if( c == ','){
                q.push(s);
                s = "";
            }else{
                s += c;
            }
        }
        if(s.size() != 0) q.push(s);
        return helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));