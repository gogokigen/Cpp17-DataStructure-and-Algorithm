#include <iostream>
#include <algorithm>
using namespace std;

class Solution {

public:
    string URLify (string& s, int trueLength) {
        //cout << s << endl;
        int spaceNum = 0;
        int index = 0;
    
        for (int i = 0; i < trueLength; i++){
            if (s[i] == ' '){
                spaceNum++;
    	   }
        }
    
        index = trueLength + 2 * spaceNum;
        if (trueLength < s.length ()){
    	    s = s.substr (0, trueLength);
        }
        
        for (int i = trueLength - 1; i >= 0; i--){
    	    if (s[i] == ' '){
    	        s[index - 1] = '0';
    	        s[index - 2] = '2';
    	        s[index - 3] = '%';
    	        index -= 3;
    	    } else {
    	        //cout << s[i] << endl;
    	        s[index - 1] = s[i];
    	        index--;
    	    }
        }
        return s;
    }

};



int main (){

    Solution *sol = new Solution ();
    string test ="ab fdde yt5";
    cout << "URLify: " << sol->URLify (test, 10) << endl;
    return 0;
}