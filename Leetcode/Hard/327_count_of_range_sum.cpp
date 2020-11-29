/*******************************************************************
* https://leetcode.com/problems/count-of-range-sum/
* Hard
* 
* Conception: 
*  1. 
*
* Given an integer array nums,
* return the number of range sums that lie in [lower, upper] inclusive.
* Range sum S(i, j) is defined as the sum of the elements in nums 
* between indices i and j (i ≤ j), inclusive.
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/problems/count-of-range-sum/discuss/78061/A-c%2B%2B-binary-search-tree-solution
*
*******************************************************************/
/*
first, then we have

sum[ i ~j ] = prefix_sum[ j ] - prefix_sum[ i ].

Back to this problem, if we maintain the prefix sums sorted,
and then are able to find out how many of the sums are less than 'lower',
say num1, and how many of the sums are less than 'upper + 1',
say num2, then 'num2 - num1' is the number of sums that lie within the range of [lower, upper].

That is to say for a current prefix sum,
s_i, we need to find how many of the previous prefix sums satisfy the equation
s_i - x < lower,
 and
s_i - x < upper + 1, where x is some one of the previous prefix sums.

We get
x > s_i - lower,
 and
x > s_i - upper - 1.
*/

class Tree{
private:
    struct TreeNode{
        int count;
        long long val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(long long val) : val(val), count(1), right(NULL), left(NULL){ }
    };
    void insert(TreeNode *&root, long long val){
        if (!root) {
            root = new TreeNode(val);
            return;
        }
        root->count++;
        if (root->val == val){
            return;
        } else if (root->val < val){
            insert(root->right, val);
        } else {
            insert(root->left, val);
        }
    }
    int greaterThan(TreeNode *root, long long val, int res){
        if (!root) return res;
        if (root->val > val){
            int tmp = root->count - (root->left ? root->left->count : 0);
            return greaterThan(root->left, val, res + tmp);
        }else if (root->val == val) {
            return res + (root->right ? root->right->count : 0);
        }else{
            return greaterThan(root->right, val, res);
        }
    }
    void destoryTree(TreeNode *root){
        if (!root) return;
        destoryTree(root->left);
        destoryTree(root->right);
        delete root;
    }
private:
    TreeNode* root;

public:
    Tree(): root(nullptr) {}
    ~Tree() {
        destoryTree(root);
    }
    void insert(long long val) {
        insert(root, val);
    }    
    int greaterThan(long long val) {
        return greaterThan(root, val, 0);
    }

};

class Solution {
private:



public:
    int countRangeSum(vector<int>& nums, int lower, int upper){
        Tree tree;
        tree.insert(0);
        long long sum = 0;
        int res = 0;
        for(int &i : nums){
            sum += i;
            int lo = tree.greaterThan(sum - lower);
            int hi = tree.greaterThan(sum - upper - 1);
            res += hi - lo;
            tree.insert(sum);
        }
        return res;
        
    }
};