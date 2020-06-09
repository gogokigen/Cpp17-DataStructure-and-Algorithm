/*******************************************************************
* https://leetcode.com/problems/range-sum-query-mutable/
* Medium
* 
* Conception: 
*  1. FenwickTree
*
* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
*
* The update(i, val) function modifies nums by updating the element at index i to val.
*
*
* Example:
* 
* Key:
*  1. 
*
* References:
*  1. https://www.youtube.com/watch?v=WbafSgetDDk
*  2. https://zxi.mytechroad.com/blog/data-structure/307-range-sum-query-mutable/
*
*******************************************************************/
class FenwickTree {
private:
    vector<int> sums;
    int lowbit(int x) {
        return x & (-x);
    }
public:
    FenwickTree(int n):sums(n + 1, 0) {}
    void update(int i, int val){
        while( i < sums.size()){
            sums[i] += val;
            i+= lowbit(i);
        }
    }
    int query(int i){
        int sum = 0;
        while( i > 0){
            sum += sums[i];
            i-=lowbit(i);
        }
        return sum;
    }
};

class NumArray {
private:
    vector<int> _nums;
    FenwickTree tree;
public:
    NumArray(vector<int>& nums): _nums(move(nums)), tree(_nums.size()){
        for(int i = 0; i < _nums.size(); i++){
            tree.update(i + 1, _nums[i]);
        }
    }
    
    void update(int i, int val) {
        tree.update(i + 1, val - _nums[i]);
        _nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        return tree.query(j + 1) - tree.query(i) ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */