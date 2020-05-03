/*******************************************************************
* https://leetcode.com/problems/ransom-note/
* Easy
* 
* Conception: 
*  1. definition of ransom
*
* Given an arbitrary ransom note string and another string containing letters from all the magazines,
* write a function that will return true if the ransom note can be constructed from the magazines ;
* otherwise, it will return false.
*
* Each letter in the magazine string can only be used once in your ransom note. 
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    //faster
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.empty() ) return true;
        if(magazine.empty()) return false;
        
        int count = 0;
        vector<int> mag(26,0);
        for(char j:ransomNote){
            mag[j-'a']++;
            count++;
        }

        for(char i:magazine){
            if(mag[i-'a'] > 0){
                mag[i-'a']--;
                count--;
                if(count == 0) return true;
            }
        }

        return count == 0;
    }
    //slow
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.empty() ) return true;
        if(magazine.empty()) return false;
        
        map<char,int> mag;
        for(auto i:magazine){
            mag[i] += 1;
        }
        
        for(auto j:ransomNote){
            if(mag.find(j) != mag.end() && mag[j] > 0){
                mag[j] -= 1;
            }else{
                return false;
            }
        }


        return true;
    }
};