/*******************************************************************
* https://leetcode.com/problems/bulls-and-cows/
* Easy
* Conception: 
*
* How many digits in said guess match your secret number 
* exactly in both digit and position (called "bulls") and 
* how many digits match the secret number but locate in the wrong position (called "cows"). 
* 
* Example:
* Input: secret = "1807", guess = "7810"
* Output: "1A3B"
* ---> exactly right: 8
* ---> number appear but position wrong: 1, 0, 7
*******************************************************************/
#include <iostream>
#include <set> //for set

using namespace std;

class Solution {
public:
    string getHint_brute(string secret, string guess) {
        multiset<char> secret_set;
        multiset<char> guess_set;
        int A = 0;
        int B = 0;
        string ret;
        for (int i = 0; i < secret.length(); i++){
            if(secret.at(i) != guess.at(i)){
                secret_set.insert(secret.at(i));
                guess_set.insert(guess.at(i));
            } else {
                ++A;
            }
        }
        
        // Use the element of guess to find the index of secret set
        multiset <char> :: iterator itr_g; 
        for (itr_g = guess_set.begin(); itr_g != guess_set.end(); ++itr_g) {
            multiset <char> :: iterator itr_s = secret_set.find(*itr_g); 
            if (itr_s == secret_set.end()) {
                cout << "No " << *itr_s << endl;
            } else {
                ++B;
                cout << *itr_s << endl;
                secret_set.erase(itr_s);
            }
        }
        return ret.append(to_string(A)).append("A").append(to_string(B)).append("B");
    }
    
    // Time: O(n)
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0, i, n = secret.length();
        int countS[10] = {0};
        int countG[10] = {0};
        for(i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                bull++;
            } else {
                // Calculate the cows:
                // How many are the number 0?
                // How many are the number 1?
                // ..
                //e.g.
                //getHint("1122","0001")
                //countS[0]==0, countG[0]==3
                //countS[1]==2, countG[1]==1
                //countS[2]==2, countG[2]==0
                // ..
                countS[secret[i] - '0']++;
                countG[guess[i] - '0']++;
            }
        }
        
        
        for( i = 0; i < 10;i++){
            cow += min(countS[i], countG[i]);
        }       
        return (to_string(bull)+"A"+to_string(cow)+"B");
    }
};

int main()
{
    Solution* sol = new Solution();
    
    //Test Case
    sol->getHint("1807","7810");//1A3B
    
    //sol->getHint("1122","0001"); //0A1B
    //cout << sol->getHint("1807","7810") << endl;
    return 0;
}