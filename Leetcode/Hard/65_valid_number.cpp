/*******************************************************************
* https://leetcode.com/problems/valid-number/
* Hard
*
* Validate if a given string can be interpreted as a decimal number.
*    Numbers 0-9
*    Exponent - "e"
*    Positive/negative sign - "+"/"-"
*    Decimal point - "."
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
    bool isNumber(string s){
        char *p = (char*)s.c_str();
        bool bSign = false;
        bool bNum = false;
        bool bDec = false;
        bool bExp = false;
        bool bExpSign = false;
        bool bExpNum = false;
        bool bTrail = false;
        while ( p && *p){
            if ((*p>='0')&&(*p<='9')){
                if (bTrail) return(false);
                if (bExp){
                    bExpNum = true;
                } else {
                    bNum = true;
                }
            }else if (*p==' '){
                if ((bDec||bSign)&&!bNum) return(false);
                if (bNum) bTrail = true;
            }else if (*p=='.'){
                if (bDec||bExp||bTrail) return(false);
                bDec = true;
            }else if (*p=='e'){
                if (!bNum||bExp||bTrail) return(false);
                bExp = true;
            }else if ((*p=='+')||(*p=='-')){
                if (bTrail) return(false);
                if (bExp){
                    if (bExpNum) return(false);
                    bExpSign = true;
                }else{
                    if (bNum||bDec||bSign) return(false);
                    bSign = true;
                }
            }else {
                return(false);
            }
            p++;
        }
        if (bExp&&!bExpNum) return(false);
        return(bNum);
    }
};
