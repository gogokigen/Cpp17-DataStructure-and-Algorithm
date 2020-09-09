/*******************************************************************
* https://leetcode.com/problems/compare-version-numbers/
* Medium
* 
* Conception: 
*  1. 
*
* Compare two version numbers version1 and version2.
* If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
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
    int compareVersion(string version1, string version2) {
        int i1=0,i2=0, n1=version1.length(), n2=version2.length();
        while (i1 < n1 || i2 < n2) {
            int v1 = 0, v2 = 0;
            while(i1 < n1 && version1[i1] != '.') v1 = v1*10 +  (version1[i1++]-'0');
            while(i2 < n2 && version2[i2] != '.') v2 = v2*10 + (version2[i2++]-'0');
            if (v1 < v2){
                return -1;
            }else if (v1 > v2) {
                return 1;
            } else {
                i1++; i2++;
            }
        }
        return 0;
    }
};