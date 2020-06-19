/*******************************************************************
* https://leetcode.com/problems/longest-duplicate-substring/
* Hard
* 
* Conception: 
*  1. https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
*
* Given a string S, consider all duplicated substrings:
* (contiguous) substrings of S that occur 2 or more times.
* (The occurrences may overlap.)
*
* Return any duplicated substring that has the longest possible length.
* (If S does not have a duplicated substring, the answer is "".)
*
*
* Example:
*
* Key:
*  1. pair<iterator,bool> emplace (Args&&... args);
*  2. The data() function writes the characters of the string into an array.
*     https://www.geeksforgeeks.org/stdstringdata-in-c/
*
*
* References:
*  1. https://leetcode.com/problems/longest-duplicate-substring/discuss/671694/C%2B%2B-Binary-Search-Solution-Using-Rabin-Carp-Algorithm
*  2. https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
*  3. https://leetcode.com/problems/longest-duplicate-substring/discuss/695101/C%2B%2B-short-O(n-log(n))-solution-with-std%3A%3Aunordered_setlessstd%3A%3Astring_viewgreater
*
*******************************************************************/
class Solution {
public:
    string longestDupSubstring(string S) {

        int n = S.length();
        string res;
        unordered_set<string_view> cache;
        //unordered_set<string>cache; //TLE
        int l = 1, r = n;

        while (l <= r) {
            int m = l + (r-l) / 2;
            //cout << "m: " << m << endl;
            bool found = false;
            for (int i = 0; i + m <= n; i++) {
                //cout << "S.data()+i: " << S.data()+i << endl;
                auto [it, existed] = cache.emplace(S.data()+i, m); //S.data()+i = char* => "abcde".data()+ 2 == cde
                if(!existed){ //existed == FALSE := S is existed this item
                    found = true;
                    res = move(*it);
                    //cout << "res: " << res << endl;
                    //for(string s:cache){
                    //    cout << "s: " << s << endl;
                    //}
                    break;
                }
            }

            if (found){
                l = m+1;
            } else {
                r = m-1;
            }
            //cout << "l: " << l << ", r: " << r << endl;
        }
        return res;
    }
};