/*******************************************************************
* https://leetcode.com/problems/bitwise-ors-of-subarrays/
* Medium
* 
* Conception: 
*  1. set
*
*
* We have an array A of non-negative integers.
* For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j),
* we take the bitwise OR of all the elements in B, obtaining a result A[i] | A[i+1] | ... | A[j].
*
* Return the number of possible results. 
*(Results that occur more than once are only counted once in the final answer.)
*
*
* Example:
*
*
* Key:
*  1. 
*
* Advanced:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        set<int> cur;
        set<int> ans;
        for(auto k:A){
            set<int> tmp;
            for(auto y:cur){
                tmp.insert(k|y);
            }
            tmp.insert(k);
            cur = tmp;

            for(auto c:cur){
                ans.insert(c);
            }

        }
        //for (auto a:ans){
        //   cout<<"ans: " << a <<endl;
        //}
        return ans.size();
    }

    int subarrayBitwiseORs(vector<int>& A) {
        vector<int> c;
        for (auto i = 0, st = 0, en = 0; i < A.size(); ++i, st = en, en = c.size()) {
            c.push_back(A[i]);
            for (auto j = st; j < en; ++j)
            if (c.back() != (c[j] | A[i])) c.push_back(c[j] | A[i]);
        }
        return unordered_set<int>(begin(c), end(c)).size();
      }
};