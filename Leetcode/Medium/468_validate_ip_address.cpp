/*******************************************************************
* https://leetcode.com/problems/validate-ip-address/
* Medium
* 
* Conception: 
*  1. 
*
* Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither. 
*
*
* Example:
*
*
* Key:
*  1. more space to save row and col 
*
* References:
*  1. https://leetcode.com/problems/validate-ip-address/discuss/689995/Validate-IP-Address-(C++-Regex-Solution-4-lines-of-code-Time-O(1)-Space-O(1))
*
*******************************************************************/
class Solution {
public:
    bool checkAtoF(char a){
        a=tolower(a);
        if( a>= 'a' && a<= 'f' ){
            return true;
        }
        return false;
    }
    bool ip4(string tmp){
        if(tmp.length() == 0 || tmp.length() > 3){
            return false;
        }
        bool zero=(tmp[0]=='0');
        if(zero and tmp.length() > 1){
            return false;
        }
        for(int i = 0; i < tmp.length(); i++){
            if(!isdigit(tmp[i])){
                return false;
            }
            if(i > 0 && zero){ //e.g. 001 or 01
                if(tmp[i] > '0'){
                    return false;
                }
            }
        }
        if(tmp.length() < 3){
            return true;
        }
        if(tmp < "256"){
            return true;
        }
        return false;
    }

    bool ip6(string tmp){
        if(tmp.length() < 1 || tmp.length() > 4){
            return false;
        }
        for(int i=0; i < tmp.length(); i++){
            if(!(isdigit(tmp[i]) || checkAtoF(tmp[i]))){
                return false;
            }
        }
        return true;
    }
    bool ipv4(vector<string> tmp){
        for(int i=0;i<tmp.size();i++){
            if(!ip4(tmp[i]))
                return false;
        }
        return true;
    }
    bool ipv6(vector<string> tmp){
        for(int i=0;i<tmp.size();i++){
            if(!ip6(tmp[i]))
                return false;
        }
        return true;
    }
    string validIPAddress(string IP) {
        vector<string> ip;
        string tmp="";
        int count=0;
        for(int i=0;i<IP.length();i++){
            if(IP[i]=='.' or IP[i]==':'){
                count++;
                if(tmp==""){
                    return "Neither";
                }
                ip.push_back(tmp);
                tmp="";
                continue;;
            }
            tmp+=IP[i];
        }
        if(tmp!=""){
            ip.push_back(tmp);
        }
        string res="Neither";
        if(ip.size()==4 && count==3){
            if(ipv4(ip)){
                res="IPv4";
            }
        } else if(ip.size()==8 && count==7){
            if(ipv6(ip)){
                res="IPv6";
            }
        }
        return res;
    }
};

//regex
class Solution {
public:
    string validIPAddress(string IP) {
        regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])"), ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");   // create regex object for regulare expression
        if(regex_match(IP, ipv4)) // match regex expression with given IP string for IPv4
            return "IPv4";
        else if(regex_match(IP, ipv6)) // match regex expression with given IP string for IPv6
            return "IPv6";
        return "Neither"; // Otherwise return "Neither"
    }
};