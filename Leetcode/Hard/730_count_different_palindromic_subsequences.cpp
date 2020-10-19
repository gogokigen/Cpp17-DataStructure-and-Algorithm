/*******************************************************************
* https://leetcode.com/problems/count-different-palindromic-subsequences/
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
    int countPalindromicSubsequences(string S) {
     
        int len = S.length();
        
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for(int i = 0; i < len-1; i++) dp[i][i] = 1, dp[i][i+1] = 2; // if length=2 then only 2 ways whether it is same or not ...ex ab..{a,b} or if aa then {a,aa};
        dp[len-1][len-1] = 1; // in the above for loop we are leaving out the (n-1,n-1)th cell..
        
        for(int sz = 3; sz <= len; sz++){
            for(int i = 0; i < len - sz + 1; i++){
                int j = i + sz - 1;
                if(S[i] == S[j]){
                    int low = i + 1; // low and high used to check how many characters of type S[i] is present 
                    int high = j - 1;
                    while(low <= high && S[low] != S[j]) low++;
                    while(low <= high && S[high] != S[j]) high--;
                   
                    if(low == high) dp[i][j] = dp[i+1][j-1]*2 + 1; // if low==high then only 1 same character..in between
                    else if(low > high) dp[i][j] = dp[i+1][j-1]*2 + 2; // if low > high  then no same character..in between
                    else dp[i][j] = dp[i+1][j-1]*2 - dp[low+1][high-1]; // if low< high and more than 1 same character..
                }
                else dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]; // if no match then simply calculate the number of subsequences form the precompured answers..
                
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + 1000000007 : dp[i][j] % 1000000007; // as we are taking mod at evey step and there is subtraction involved in the above 
            }                                        //steps there might be scenarios where after taking the mod it might become small and the term to be subtracted might be larger ..therefore we add mod...(number theory rules..)
            
        }
        return dp[0][len-1];
        
    }
};
