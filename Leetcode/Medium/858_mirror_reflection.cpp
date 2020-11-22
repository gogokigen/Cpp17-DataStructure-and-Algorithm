/*******************************************************************
* https://leetcode.com/problems/mirror-reflection/
* Medium
* 
* Conception: 
*  1. 
*
* There is a special square room with mirrors on each of the four walls.
* Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.
* The square room has walls of length p, and
* a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.
* Return the number of the receptor that the ray meets first.
* (It is guaranteed that the ray will meet a receptor eventually.)
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/problems/mirror-reflection/discuss/939143/C++-Geometry-mirror-game
*
*******************************************************************/
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int m = 1; // extension count of room
        int n = 1; // reflection count of laser ray

        while(m * p != n * q){
            n++;
            m = n * q / p;
        }

        if (m % 2 == 0 && n % 2 == 1) return 0;
        if (m % 2 == 1 && n % 2 == 1) return 1;
        if (m % 2 == 1 && n % 2 == 0) return 2;
        return -1;
    }
};