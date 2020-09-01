/*******************************************************************
* https://leetcode.com/problems/read-n-characters-given-read4/
* Easy
* 
* Conception: 
*  1. Copy what you need
*
* Given a file and assume that you can only read the file using a given method read4,
* implement a method to read n characters.
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
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int copiedChars = 0, readChars = 4;
        char buf4[4];
        
        while (copiedChars < n && readChars == 4) {
            readChars = read4(buf4);
            
            for (int i = 0; i < readChars; ++i) {
                if (copiedChars == n){
                    return copiedChars;
                }
                buf[copiedChars] = buf4[i];
                copiedChars++;    
            }    
        }
        return copiedChars;
    }
};