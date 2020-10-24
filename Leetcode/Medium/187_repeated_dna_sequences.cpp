/*******************************************************************
* https://leetcode.com/problems/repeated-dna-sequences/
* Medium
* 
* Conception: 
*  1. 
*
* All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T',
* for example: "ACGAATTCCG". When studying DNA,
* it is sometimes useful to identify repeated sequences within the DNA.
*
* Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
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
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        unordered_map<string,int> mp;

        if(s.length() <= 10){
            return v;
        }

        for(int i = 0; i <= s.length() - 10; i++){
            mp[s.substr(i,10)]++;
        }

        for(auto x:mp){
            if(x.second>1){
                v.push_back(x.first);
            }
        }
        return v;
    }
};