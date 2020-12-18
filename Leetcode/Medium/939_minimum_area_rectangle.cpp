/*******************************************************************
* https://leetcode.com/problems/minimum-area-rectangle/
* Medium
* 
* Conception: 
*  1.
*
* Given a set of points in the xy-plane,
* determine the minimum area of a rectangle formed from these points,
* with sides parallel to the x and y axes.
*
* If there isn't any rectangle, return 0.
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n_row = points.size();
        int n_col = n_row ? points[0].size():0;
        
        unordered_map<int, set<int>> rows;
        for (auto& point: points) {
            int x = point[0], y = point[1];
            rows[x].insert(y);
        }

        int ans = INT_MAX;
        for (auto i = rows.begin(); i != rows.end(); ++i){
            for (auto j = next(i); j != rows.end(); ++j) {
                if (i->second.size() < 2 || j->second.size() < 2) continue;
                
                vector<int> x;
                set_intersection(begin(i->second), end(i->second),
                                   begin(j->second), end(j->second), back_inserter(x));
                for (int k = 1; k < x.size(); ++k){
                    ans = min(ans, abs(j->first - i->first) * (x[k] - x[k - 1]));
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};