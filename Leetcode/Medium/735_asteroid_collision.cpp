/*******************************************************************
* https://leetcode.com/problems/asteroid-collision/
* Medium
* 
* Conception: 
*  1. 
*
* We are given an array asteroids of integers representing asteroids in a row.
* For each asteroid, the absolute value represents its size, and the sign represents its direction
* (positive meaning right, negative meaning left).
* Each asteroid moves at the same speed.
*
* Find out the state of the asteroids after all collisions.
* If two asteroids meet, the smaller one will explode.
* If both are the same size, both will explode.
* Two asteroids moving in the same direction will never meet.
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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        stack<int> left, right;
        for(auto i: asteroids){
        // conditions to keep in mind : when left asteroid comes and the right asteroid stack is not empty, rest all can be added to the stack without issue.
            if(i <= 0 ){
                if(!right.empty()){
                    while(!right.empty() && (-i)>right.top()){
                        right.pop();
                    }
                    if(!right.empty() && right.top()==(-i)) {
                        right.pop();
                        continue;
                    }
                }

                if(right.empty()) {
                    left.push(-i);
                    //contents of left stack can be added as is so push them right now
                    v.push_back(i);
                }
            }else {
                right.push(i);
            }
        }

        vector<int>temp;
        while(!right.empty()){
            temp.push_back(right.top());
            right.pop();
        }

        // reverse add the right stack contents
        v.insert(v.end(),temp.rbegin(),temp.rend());
        return v;
    }
};