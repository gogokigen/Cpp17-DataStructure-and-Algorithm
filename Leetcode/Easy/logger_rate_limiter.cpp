/*******************************************************************
* https://leetcode.com/problems/logger-rate-limiter/
* Easy
* Conception: 
*
* Design a logger system that
* receive stream of messages along with its timestamps,
* each message should be printed if and only if it is not printed in the last 10 seconds.
*
* Given a message and a timestamp (in seconds granularity), 
* return true if the message should be printed in the given timestamp, otherwise returns false.
*
* It is possible that several messages arrive roughly at the same time.
* 
* Example:
* Logger logger = new Logger();
*
* // logging string "foo" at timestamp 10
* logger.shouldPrintMessage(10,"foo"); returns false;
*
*******************************************************************/

#include <iostream>
#include <map> //for map
#include <unordered_map> //for unordered_map
using namespace std;


class Logger {
public:
    unordered_map<string, int> msg_map;
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        cout << "timestamp: " << timestamp << endl;
        cout<< "message: " << message << endl;
        
        if(msg_map.find(message) == msg_map.end()){
            msg_map.insert(pair<string, int>(message, timestamp));
            return true;
        }else{
            if(timestamp - msg_map[message] < 10){
                return false;
            }else{
                msg_map[message] = timestamp;
                return true;
            }
        }
        return false
    }
};

int main()
{
    //Test Cases
    multimap<string, int> test;
    test.insert(pair<string, int>("", 0));
    test.insert(pair<string, int>("foo", 1));
    test.insert(pair<string, int>("bar", 2));
    test.insert(pair<string, int>("foo", 3));
    test.insert(pair<string, int>("bar", 8));
    test.insert(pair<string, int>("foo", 10));
    test.insert(pair<string, int>("foo", 11));

    multimap<string, int>::iterator itr = test.begin();
    Logger* obj = new Logger();
    for (itr = test.begin(); itr != test.end(); itr++){
        bool param_1 = obj->shouldPrintMessage(itr->second, itr->first);
        cout << "Result: "<< param_1 << endl;
    }
    //[null,true,true,false,false,false,true]
    return 0;
}