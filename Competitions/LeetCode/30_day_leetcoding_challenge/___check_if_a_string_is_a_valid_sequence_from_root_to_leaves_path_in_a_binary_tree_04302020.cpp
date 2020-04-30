/*******************************************************************
* Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
* Medium
* 
* Conception: 
*  1.
*
* Given a binary tree where each path going from the root to any leaf form a valid sequence,
* check if a given string is a valid sequence in such binary tree. 
*
* We get the given string from the concatenation of an array of integers arr and
* the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.
*
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
    bool visited(TreeNode* current, int index, vector<int>& arr){
        if(!current) return false;
        
        //end case
        if(index == arr.size()-1){
            if(current->val == arr[index]){
                return !current->left && !current->right;
            }else{
                return false;
            }
        }
        
        //generall case
        if(current->val == arr[index]){
            return visited(current->left , index+1, arr)||visited(current->right , index+1, arr);
        }
        return false;
    }

    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(!root) return false;

        TreeNode* current = root;
        return visited(root, 0, arr);
    }
};