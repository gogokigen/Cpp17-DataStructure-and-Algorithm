/*******************************************************************
* https://leetcode.com/problems/minimum-window-substring/
* Hard
* 
* Conception: 
*  1. 
*
* Given two strings s and t,
* return the minimum window in s which will contain all the characters in t.
* If there is no such window in s that covers all characters in t,
* return the empty string "".
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
class Solution {
public:
    void fillFreq(vector<int>& freq, string str){
        for(char c : str)
            freq[c-'A']++;
    }
    
    string minWindow(string s, string t) {

        vector<int> freq( 256, 0), window_freq( 256, 0);
        int start = 0, n = s.size();
        int min_wind = INT_MAX, i, j, ctr = 0;
        fillFreq( freq, t);
        
        for(int end = 0; end < n; end++){
            int ind =  s[end]-'A';
            
            // check if char exist in t and not all of it's instances are already in window...
            if(freq[ind] && window_freq[ind] < freq[ind]){ 
                ctr++;
            }
            window_freq[ind]++; // add char in window
            
            if(ctr == t.size()){ // window found with all char's of t
                // try to reduce current window so that all characters of t are there
                while( start < end && (window_freq[s[start]-'A'] > freq[s[start]-'A'] || freq[s[start]-'A']==0)){
                    window_freq[s[start]-'A']--;
                    start++;
                }
                
                if(min_wind > end - start + 1){
                    min_wind = end - start + 1;
                    i = start;
                }
            }
        }
        return min_wind == INT_MAX ? "" : s.substr(i,min_wind);
    }
};