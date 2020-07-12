/*******************************************************************
* https://leetcode.com/problems/basic-calculator-iii/
* Hard
* 
* Conception: 
*  1.
*
* Implement a basic calculator to evaluate a simple expression string.
*
* The expression string may contain open ( and closing parentheses ),
* the plus + or minus sign -, non-negative integers and empty spaces .
*
* The expression string contains only non-negative integers, +, -, *, / operators ,
* open ( and closing parentheses ) and empty spaces .
* The integer division should truncate toward zero.
*
* You may assume that the given expression is always valid.
* All intermediate results will be in the range of [-2147483648, 2147483647].
*
*
* Example:
* 
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
    int calculate(string s) {
        int i = 0;
        return parseExpr(s, i);
    }
    
    int parseExpr(string& s, int& i) {
        vector<int> nums;
        char op = '+';
        for (; i < s.length() && op != ')'; i++) {
            if (s[i] == ' ') continue;
            long n = s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i);
            switch(op) {
                case '+' : nums.push_back(n); break;
                case '-' : nums.push_back(-n); break;
                case '*' : nums.back() *= n; break;
                case '/' : nums.back() /= n; break;
            }            
            op = s[i];
        }
        int res = 0;
        for (int n : nums) res += n;
        return res;
    }
    
    long parseNum(string& s, int& i) {
        long n = 0;
        while(i < s.length() && isdigit(s[i])){
             n = (long) s[i] - '0' + 10 * n;
            i++;
        }
        return n;
    }
};


class Solution {
public:
    int calculate(string s) {
        s=s+"&";
        char sign='+';
        long int curr_sum = 0;
        long int pre = 0;
        long int curr = 0;
        int i = 0;
        vector<int> stack_sum;
        vector<char> bracket_stack;
        vector<int> stack_pre;
        while(i<s.size()){
            if (s.at(i)!=' '){
                if (s.at(i)=='('){
                    bracket_stack.push_back(sign); 
                    stack_sum.push_back(curr_sum);
                    stack_pre.push_back(pre);   
                    curr_sum=0;
                    pre=0;
                    sign='+';   
                }else if (isdigit(s.at(i))){  
                    long int temp= s.at(i)-'0';
                    curr=curr*10+temp;             
                } else {

                    if (sign=='+'){                
                        curr_sum+=pre;
                        pre=curr;    
                    }else if (sign=='-'){
                        curr_sum+=pre;
                        pre=-curr;
                    } else if (sign=='*'){
                        pre=pre*curr;
                    }else if (sign=='/'){
                        pre=pre/curr;
                    }

                    sign=s.at(i);
                    curr=0;
                    if (s[i]==')'){
                        if ((sign=='*')||(sign=='/')) 
                            curr=curr_sum+pre;
                        else if (sign=='-') 
                            curr=curr_sum+pre-curr;   
                        else
                            curr=curr_sum+pre+curr;   

                        sign=bracket_stack.back();
                        bracket_stack.pop_back();   
                        pre=stack_pre.back();
                        stack_pre.pop_back();   
                        curr_sum=stack_sum.back();
                        stack_sum.pop_back(); 
                        if ((i+1)>s.size()){
                            if (s[i+1]!=')'){
                                i++;
                            }
                        }
                    }
                }
            }
            i++;
        } 
        if ((sign=='*')||(sign=='/'))          
            return curr_sum+pre   ;
        if (sign=='-') return curr_sum+pre-curr;   
            return curr_sum+pre+curr;   
    }
};