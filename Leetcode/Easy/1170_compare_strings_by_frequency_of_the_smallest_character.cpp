/*******************************************************************
* https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
* Easy
* 
* Conception: 
*  1. 
*
* Given a positive integer n, find the least number of perfect square numbers
* (for example, 1, 4, 9, 16, ...) which sum to n.
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
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> v1,v2,v3;

        for(auto s : queries){
            int countS = 1;
            sort(s.begin(), s.end());
            for(int i = 1; i < s.size(); i++){
                //cout<< "s[i]: " << s[i] << endl;
                if(s[0]==s[i]){
                    countS++;
                }
            }
            //cout<< "countS: " << countS<< endl;
            v1.push_back(countS);    
        }
        //for(int i=0; i<v1.size(); i++) cout<<v1[i]<<" ";
    
    
        for(auto p : words){
            int countP = 1;
            sort(p.begin() , p.end());
            for(int i=1;i<p.size(); i++){
                //cout<< "p[i]: " << p[i] << endl;
                if(p[0]==p[i]){
                    countP++;
                }
            }
            //cout<< "countP: " << countP<< endl;
            v2.push_back(countP);    
        }
       // for(int i=0; i<v2.size(); i++) cout<<v2[i]<<" ";
    
    
        for(int i = 0; i < v1.size(); i++){
            int count = 0;
            for(int j=0; j < v2.size(); j++){
                if(v1[i] < v2[j] ){
                    count++; 
                }
            }
            v3.push_back(count);
        }
       //for(int i=0; i<v3.size(); i++){
       //    cout<<v3[i]<<" ";
       //}
       return v3;
    }
};