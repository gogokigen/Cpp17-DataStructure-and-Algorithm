/*******************************************************************
* https://leetcode.com/problems/serialize-and-deserialize-bst/
* Medium
* 
* Conception: 
*  1. 
*
* Serialization is converting a data structure or object into a sequence of bits
* so that it can be stored in a file or memory buffer,
* or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
*
* Design an algorithm to serialize and deserialize a binary search tree.
* There is no restriction on how your serialization/deserialization algorithm should work.
* You need to ensure that a binary search tree can be serialized to a string,
* and this string can be deserialized to the original tree structure.
*
* The encoded string should be as compact as possible.
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
    
    queue<TreeNode*> q;
    q.push(root);
    string s;
    
    if(!root) {
        return s;
    }
    // cout << root->left->val << endl;
    while(!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        s += to_string(curr->val)+"|";
        if(curr->left){
            q.push(curr->left);
        }
        
        if(curr->right) {
            q.push(curr->right);
        }
    }

    return s;
}


TreeNode* insert(TreeNode* root,int data) {
    if(!root) {
        root = new TreeNode;
        root->val = data;
        root->left = root->right = NULL;
        return root;
    }
    
    if(root->val == data) {
        return root;
    }
    
    if(data < root->val) {
        root->left = insert(root->left,data);
    }else{
        root->right = insert(root->right,data);
    }
    
    return root;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    
    if(data.size() == 0) {
        return NULL; 
    }
    vector<string> strings;
    int n = data.size();
    
    char char_array[n + 1]; 
    strcpy(char_array, data.c_str());
    
    
    char *s = strtok(char_array, "|");
    
    while(s) {
        strings.push_back(s);
        s = strtok(NULL, "|");
    }
    
    TreeNode *root = NULL;
    for(string s: strings) {
        root = insert(root, stoi(s));
    }
    
    return root;
    
    
}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;