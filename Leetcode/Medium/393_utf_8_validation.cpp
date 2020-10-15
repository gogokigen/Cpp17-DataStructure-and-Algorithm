/*******************************************************************
* https://leetcode.com/problems/utf-8-validation/
* Medium
*
* A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
*    For 1-byte character, the first bit is a 0, followed by its unicode code.
*    For n-bytes character, the first n-bits are all one's, the n+1 bit is 0,
*        followed by n-1 bytes with most significant 2 bits being 10.
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
    bool validUtf8(std::vector<int>& data){
        if (data.size() == 0)
            return false;

        int dataSize = data.size();	
        int ones = 0;
        for (int index = 0; index < dataSize; ++index){
            std::bitset<8> temp(data[index]);

            if (ones > 0){
                if (temp[7] != 1 || temp[6] != 0)
                    return false;
                --ones;
            }else{
                if (temp[7] == 0)
                    continue;
                if (index >= dataSize - 1)
                    return false;

                for (int i = 6; i >= 0; --i){
                    if (temp[i] == 1)
                        ++ones;
                    else if (temp[i] == 0)
                        break;
                }

                if (ones == 0 || ones > 3)
                    return false;
            }
        }
        return true;
    }
};
