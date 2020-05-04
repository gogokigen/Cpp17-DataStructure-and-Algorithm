/*******************************************************************
* 
* Practice: Implement substr(idx, length) in C++
* 
* string substr (size_t pos, size_t len) const;
* Parameters:
* @pos: Position of the first character to be copied.
* @len: Length of the sub-string.
* @size_t: It is an unsigned integral type.
*
* Return value: It returns a string object.
*
* References: 
*  1. https://www.geeksforgeeks.org/substring-in-cpp/
*  2. https://www.techiedelight.com/implement-substr-function-c/
*
* Key:
*  1. 
*
*******************************************************************/
#include <iostream>
using namespace std;

class Solution {
private:
    string source = NULL;
public:
    
    Solution(string str):source(str) {
    };

    string substr(int idx, int length){
        if(idx >= source.length()) return "";
        string ret;
        for(int i = idx; i < idx + length; i++){
            ret = ret + source[i];
        }
        ret = ret + '\0';
        return ret;
    } 

};

int main(){


    Solution* sol = new Solution("TestString");
    cout<< "TestString.substr(1,3): " << sol->substr(1,3) << endl;

    return 0;
}