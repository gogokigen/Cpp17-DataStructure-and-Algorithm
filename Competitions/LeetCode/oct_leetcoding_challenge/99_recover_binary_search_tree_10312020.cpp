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
//Method 1:
class Solution {
public:
    TreeNode *first;
    TreeNode *second;
    TreeNode *prev;
    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        first = NULL;
        second = NULL;
        prev = NULL;
        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void inorder(TreeNode *root){
        if(!root)
            return;
        inorder(root->left);
        if(first==NULL && prev!=NULL && prev->val >= root->val)
            first = prev;
        if(first!=NULL && prev->val >= root->val)
            second = root;
        prev = root;
        inorder(root->right);
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
