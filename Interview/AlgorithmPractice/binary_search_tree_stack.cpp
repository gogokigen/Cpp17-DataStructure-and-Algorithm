/*******************************************************************
* 
* Practice: DFS with Stack
* 
* References: 
*  1. Recursive https://algorithms.tutorialhorizon.com/depth-first-searchtraversal-in-binary-tree/
*     https://www.geeksforgeeks.org/dfs-traversal-of-a-tree-using-recursion/
*  2. Iterative https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
*
* Key:
*  1. Stack
*  2. recursive
*  3. inorder traversal
*
*******************************************************************/
#include <iostream>
#include <bits/stdc++.h>  //stack
using namespace std;

class Node {
public:
    Node(){};

    int val;
    Node* left = NULL;
    Node* right = NULL;
};


class Solution {
public:
    Solution(){};
    
    // Method 1
    void DFS_recuersion(Node* root){
        if (root == NULL) 
        return; 

        cout<< root->val << endl;
        DFS(root->left);
        DFS(root->right);
    }
    
    // Method 2, O(n)
    void DFS(Node* root){
        if (root == NULL) 
            return;

        stack<Node*> s;
        Node* cur = root;

        while(!s.empty() || cur != NULL){
            if(cur != NULL){
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                cout<< cur->val << endl;
                cur = cur->right;

            }
        }
    }

};

int main()
{
/*
             1
          2     3
         4 5   7   8
       6          10 9
                12    11
*/
    //Test Cases
    Node node[12];
    node[0].val = 1;
    node[0].left = &node[1];
    node[0].right = &node[2];

    node[1].val = 2;
    node[1].left = &node[3];
    node[1].right = &node[4];

    node[2].val = 3;
    node[2].left = &node[6];
    node[2].right = &node[7];
    
    node[3].val = 4;
    node[3].left = &node[5];
    node[3].right = NULL;

    node[4].val = 5;
    node[4].left = NULL;
    node[4].right = NULL;

    node[5].val = 6;
    node[5].left = NULL;
    node[5].right = NULL;

    node[6].val = 7;
    node[6].left = NULL;
    node[6].right = NULL;

    node[7].val = 8;
    node[7].left = &node[9];
    node[7].right = &node[8];

    node[8].val = 9;
    node[8].left = NULL;
    node[8].right = &node[10];

    node[9].val = 10;
    node[9].left = &node[11];
    node[9].right = NULL;
    
    node[10].val = 11;
    node[10].left = NULL;
    node[10].right = NULL;

    node[11].val = 12;
    node[11].left = NULL;
    node[11].right = NULL;


    Solution* sol = new Solution;
    sol->DFS(&node[0]);
    //1 2 4 6 5 3 7 8 10 12 9 11

    return 0;
}