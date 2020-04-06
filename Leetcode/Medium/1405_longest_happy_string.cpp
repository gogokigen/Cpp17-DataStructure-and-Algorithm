/*******************************************************************
* https://leetcode.com/problems/longest-happy-string/
* Medium
* 
* Conception: 
*  1. https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
*
* A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.
*
* Given three integers a, b and c, return any string s, which satisfies following conditions:
*
*    s is happy and longest possible.
*    s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
*    s will only contain 'a', 'b' and 'c' letters.
*
* If there is no such string s return the empty string "".
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
*  1. https://leetcode.com/problems/longest-happy-string/discuss/565594/C%2B%2B-PriorityQueue-(maxHeap)-solution-O(N)
*
*******************************************************************/
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>  pq;   //<cnt, char>
        if (a) pq.push({a,'a'});
        if (b) pq.push({b,'b'});
        if (c) pq.push({c,'c'});
        string res;
        while (!pq.empty()) {
            auto [cnt1, t1] = pq.top(); pq.pop();
            //if t1 differs from res.back(), we can insert t1 two times, 
            //otherwise, we can only insert t1 once
            int limit = (!res.empty() && res.back()==t1) ? 1 : 2;
            for (int i=0; i<limit && cnt1>0; i++, cnt1--) res.push_back(t1);
            
            if (pq.empty()) break;   //case w/ 1 char left only, break
            
            auto [cnt2, t2] = pq.top(); pq.pop();
            res.push_back(t2);      //insert t2 for one time
            cnt2--;

            if (cnt1>0) pq.push({cnt1,t1});//add rem chars&cnt back to pq
            if (cnt2>0) pq.push({cnt2,t2});
        }
        return res;
    }
};