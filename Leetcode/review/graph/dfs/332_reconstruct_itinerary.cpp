/*******************************************************************
* https://leetcode.com/problems/reconstruct-itinerary/
* Medium
* 
* Conception: 
*  1.
*
* Given a list of airline tickets represented by pairs of departure and arrival airports [from, to],
* reconstruct the itinerary in order.
* All of the tickets belong to a man who departs from JFK.
* Thus, the itinerary must begin with JFK.
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
private:
    map<string, priority_queue<string, vector<string>, greater<string>>> queue;
    vector<string> ret;
    void dfs(string next){
        while(!queue[next].empty()){
            string s = queue[next].top();
            queue[next].pop();
            dfs(s);
        }
        ret.insert(ret.begin(), next);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto& t:tickets){
            queue[t[0]].push(t[1]);
        }
        
        dfs("JFK");
        return ret;
    }
};
