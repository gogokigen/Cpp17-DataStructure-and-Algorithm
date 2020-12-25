/*******************************************************************
* https://leetcode.com/problems/binary-tree-cameras/
* Hard
* 
* Conception: 
*  1. 
*
* Given a binary tree, we install cameras on the nodes of the tree. 
* Each camera at a node can monitor its parent, itself, and its immediate children.
* Calculate the minimum number of cameras needed to monitor all nodes of the tree.
*
* Reference:
*  1. 
*
* Key:
*  1. 
*
*******************************************************************/
/*
For an index i, we define two pointers, left and right. left is defined as the smallest index such that A[left...i] has K distinct elements, right is defined as the largest index such that A[right...i] has K distinct element. Therefore, the number of subarrays ending at i that have K distinct elements is right-left+1. Each index enters any of the maps at most once, and exits at at most once. Therefore the complexity is O(N).
*/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int res = 0;
        int left = 0, right = 0;
        unordered_map<int,int> mpL, mpR;
        for(int i = 0; i < A.size(); i++){
            mpL[A[i]]++;
            mpR[A[i]]++;
            if(mpR.size()<K)
                continue;
            while(mpL.size()>K){
                mpL[A[left]]--;
                if(mpL[A[left]]==0)
                    mpL.erase(A[left]);
                left++;
            }
            while(mpR.size()>K){
                mpR[A[right]]--;
                if(mpR[A[right]]==0)
                    mpR.erase(A[right]);
                right++;
            }
            while(mpR[A[right]]>1)
                mpR[A[right]]--, right++;
            res += right-left+1;
        }
        return res;
    }
};
