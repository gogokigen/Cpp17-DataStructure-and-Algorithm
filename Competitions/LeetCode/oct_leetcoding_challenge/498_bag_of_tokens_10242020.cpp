/*******************************************************************
* https://leetcode.com/problems/bag-of-tokens/
* Medium
* 
* Conception: 
*  1. 
*
* You have an initial power of P, an initial score of 0,
* and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).
*
* Your goal is to maximize your total score by potentially playing each token in one of two ways:
*    If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
*    If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
*
* Each token may be played at most once and in any order. You do not have to play all the tokens.
* Return the largest possible score you can achieve after playing any number of tokens.
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
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int l = 0;
        int r = tokens.size()-1;
        int tmp = 0;
        int res = 0;
        
        /*
            sort it, so smallest at the left, max on the right,
            to max scores, must eat smallest from the left
            to max scores, to recover power, must eat right most.
            
            score only increase during taking from left, track the max results.
        */
        
        while(l <= r){
            if(tokens[l] <= P){
                P -= tokens[l];
                ++tmp;
                ++l;
                res = max( tmp, res);
            }else if(tmp){
                P += tokens[r];
                --tmp;
                --r;
            }else{
                break;
            }
        }
        return res;
    }
};