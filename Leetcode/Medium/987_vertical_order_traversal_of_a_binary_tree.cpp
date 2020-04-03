/*******************************************************************
* https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
* Medium
* 
* Conception: 
*  1. set sorting, default increasing
*  2. 
*
* Given a binary tree, return the vertical order traversal of its nodes values.
* For each node at position (X, Y),
* its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
*
* If two nodes have the same position,
* then the value of the node that is reported first is the value that is smaller.
*
* Return an list of non-empty reports in order of X coordinate. 
* Every report will have a list of values of nodes.
*
*
* Example:

* 
* Key:
*  1. https://riptutorial.com/cplusplus/example/28000/changing-the-default-sort-of-a-set
*
* Advanced:
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
class Solution {
public:
    
    map<int, set<pair<int,int>>> table;
    void constructPosition(TreeNode* root, int x, int y){

        if(root == nullptr) return;

        table[x].insert({y , root->val});

        // set default sorting increasing
        // therefor, if you want (x,y): (0, 0) > (0, -2)
        //           we sets its y as       0         2
        constructPosition(root->left, x - 1, y + 1); // originally, saving y - 1
        constructPosition(root->right, x + 1, y + 1);// if using minus, (0, -2) is ahead for (0, 0)
        return;
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        constructPosition(root, 0, 0);
        
        vector<vector<int>> ret;

        for(auto t : table){
            vector<int> list;
            for(auto i : t.second){
                list.push_back(i.second);
            }
            ret.push_back(list);
        }
        
        return ret;

    }
};