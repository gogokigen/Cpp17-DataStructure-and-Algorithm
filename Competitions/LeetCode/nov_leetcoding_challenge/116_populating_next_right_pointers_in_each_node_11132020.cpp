/*******************************************************************
* https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
* Medium
* 
* Conception: 
*  1. 
*
* Given a collection of numbers, nums, that might contain duplicates,
* return all possible unique permutations in any order.
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
        if(root and root->left) {
            root->left->next = root->right;
            Node* c1 = root->left;
            Node* c2 = root->right;

            while(c1->right){
                c1->right->next = c2->left;
                c1 = c1->right;
                c2 = c2->left;
            }
            root->left = connect(root->left);
            root->right = connect(root->right);
        }
        return root;
    }
};