/*******************************************************************
* https://leetcode.com/problems/recover-binary-search-tree/
* Hard
*
* Two elements of a binary search tree (BST) are swapped by mistake.
* Recover the tree without changing its structure.
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Method 1:
class Solution {
    
public:
    TreeNode* shouldSmaller;
    TreeNode* shouldBigger;
    TreeNode* preRoot;
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        if(!shouldSmaller && preRoot && preRoot->val >= root->val){
            shouldSmaller = preRoot;
        }
        if(shouldSmaller && preRoot->val >= root->val){
            shouldBigger = root;
        }
        preRoot = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;
        shouldSmaller = NULL;
        shouldBigger = NULL;
        preRoot = NULL;
        
        inorder(root);
        
        int tmp = shouldSmaller->val;
        shouldSmaller->val = shouldBigger->val;
        shouldBigger->val = tmp;
    }
};

// Method 2: slower
class Solution {
public:
	void recoverTree(TreeNode* root) {
		vector<pair<int,int>> pairss;
		vector<int> inOrderArray;
		inOrderTraversal(root, inOrderArray);
		findPairs(inOrderArray, pairss);
		if(pairss.size() == 1){
			findAndSwap(pairss[0].first, pairss[0].second, root);
		}
		if(pairss.size() == 2){
			findAndSwap(pairss[0].first, pairss[1].second, root);
		}
		return;
	}

	void findAndSwap(int first, int second, TreeNode* root){
		cout << first << second << endl;
		auto tempFirst = findElementByBFS(root, first);
		auto tempSecond = findElementByBFS(root, second);

		int x = tempFirst->val;
		tempFirst->val = tempSecond->val;
		tempSecond->val = x;
	}

	TreeNode* findElementByBFS(TreeNode* root, int first){
		if(root == NULL){
			return root;
		}
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty()){
			auto current = que.front();
			que.pop();
			if(current->val == first){
				return current;
			}
			if(current->left)
				que.push(current->left);
			if(current->right)
				que.push(current->right);
		}
		return root;
	}

	void findPairs(vector<int> &inOrderArray, vector<pair<int,int>> &pairss){
		for(int i=0;i<inOrderArray.size()-1; i++){
			if(inOrderArray[i] >= inOrderArray[i+1]){
				pairss.push_back({inOrderArray[i], inOrderArray[i+1]});
			}
		}
	}

	void inOrderTraversal(TreeNode* root, vector<int> &vec){
		if(root==NULL){
			return;
		}

		inOrderTraversal(root->left, vec);
		vec.push_back(root->val);
		inOrderTraversal(root->right, vec);
	}
};
