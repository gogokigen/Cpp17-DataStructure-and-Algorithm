/*******************************************************************
* https://leetcode.com/problems/expression-add-operators/
* Hard
*
* Given a string that contains only digits 0-9 and a target value,
* return all possibilities to add binary operators (not unary) +, -, or * between the digits
* so they evaluate to the target value.
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
    vector<string> arr;
public:
    void helper(string & num, int target, int start, int end, long sum, string s, int last){
        if(target == sum && start == num.length()){
            arr.push_back(s);
            return;
        }
        if(start <= end){
            string temp = "";
            for(int i = start; i<=end; i++){
                if(i != start && num[start] == '0')
                    break;
                temp += num[i];
                long n = stol(temp);
                if(start == 0)
                    helper(num, target, i+1, end, n, temp, n);
                else{
                    helper(num, target, i+1, end, sum+n,  s+"+"+temp, n);
                    helper(num, target, i+1, end, sum-n,  s+"-"+temp, -1*n);
                    helper(num, target, i+1, end, sum - last +last*n,  s+"*"+temp, last*n);
                }
            }
        }
    }
    
    
    vector<string> addOperators(string num, int target) {
        helper(num, target, 0, num.length() - 1, 0, "", 0);
        return arr;
    }
};
