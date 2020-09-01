/*******************************************************************
* https://leetcode.com/problems/largest-time-for-given-digits/
* Easy
* 
* Conception: 
*  1. 
*
* Given an array of 4 digits, return the largest 24 hour time that can be made.
*
* The smallest 24 hour time is 00:00, and the largest is 23:59.
* Starting from 00:00, a time is larger if more time has elapsed since midnight.
*
* Return the answer as a string of length 5. 
* If no valid time can be made, return an empty string.
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
    string largestTimeFromDigits(vector<int>& A) {

        int max_time = -1;
        // prepare for the generation of permutations next.
        sort(A.begin(), A.end());

        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];

            if (hour < 24 && minute < 60) {
                int new_time = hour * 60 + minute;
                max_time = new_time > max_time ? new_time : max_time;
            }
        } while(next_permutation(A.begin(), A.end()));

        if (max_time == -1) {
            return "";
        } else {
            ostringstream strstream;
            strstream << setw(2) << setfill('0') << max_time / 60
               << ":" << setw(2) << setfill('0') << max_time % 60;
            return strstream.str();
        }
    }
};