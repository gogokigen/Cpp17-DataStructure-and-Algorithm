/*******************************************************************
* https://leetcode.com/problems/roman-to-integer/
* Easy
* 
* Conception: 
*  1. 
*
* Roman string to integer
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
    int romanToInt(string s) {
        int output = 0;
        for (int i = 0; i < s.size(); i++){
            switch (s[i]){
                case 'V':
                    output +=5;
                    break;
                case 'X':
                    if (s[i+1] == 'L'){
                        output += 40;
                        i++;
                    } else if (s[i+1] =='C'){
                        output += 90;
                        i++;
                    } else{
                        output += 10;
                    }
                    break;
                case 'L':
                    output +=50;
                    break;
                case 'C': //all C cases
                    if (s[i+1] == 'D'){
                        output += 400;
                        i++;
                    } else if (s[i+1] == 'M'){
                        output += 900;
                        i++;
                    } else{
                        output += 100;
                    }
                    break;
                case 'D':
                    output += 500;
                    break;
                case 'M':
                    output += 1000;
                    break;
                case 'I':
                    if (s[i+1] == 'V'){
                        output +=4;
                        i++;
                    } else if (s[i+1] == 'X'){
                        output += 9;
                        i++;
                    } else if (s[i+1] == 'I'){
                        if (s[i+2] == 'I'){
                            output +=3;
                            i+=2;
                        } else {
                            output +=2;
                            i++;
                        }
                    } else {
                        output +=1;
                    }
                    break;
                }
            }
        return output;
    }
};