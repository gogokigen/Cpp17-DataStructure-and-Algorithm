/*******************************************************************
* https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
* Medium
* 
* Conception: 
*  1. 
*
* Populate each next pointer to point to its next right node.
* If there is no next right node, the next pointer should be set to NULL.
*
* Initially, all next pointers are set to NULL.
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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL; //Edge Case
        
        queue<Node*> q;
        
        //Trick: Push NULL to maintain depth information
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if (curr == NULL) {
                if (q.size() > 0){
                    q.push(NULL);
                }
            } else {
                curr->next = q.front();
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }
        return root;
    }
};