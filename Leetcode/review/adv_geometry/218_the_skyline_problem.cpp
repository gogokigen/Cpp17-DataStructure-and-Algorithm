/*******************************************************************
* https://leetcode.com/problems/the-skyline-problem/
* Hard
* 
* Conception: 
*  1. 
*
* A city's skyline is the outer contour of the silhouette formed by all the buildings in that city
* when viewed from a distance.
* Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo,
* write a program to output the skyline formed by these buildings collectively.
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
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
            // use walls to record buildings; left wall is an insertion event, and right wall is a deletion event
            vector<vector<int>> walls, ans;                  // first: x, second: height
            for (auto b : buildings) {
                // push in left / right walls
                // let left wall has negative height to ensure left wall goes to multiset first if with same 'x' as right wall
                walls.push_back({b[0], -b[2]}); // enter event
                walls.push_back({b[1], b[2]}); // leaving event
            }
            sort(walls.begin(), walls.end());                   // sort walls for scanning lines

            multiset<int> leftWallHeights = {0};                // keep left wall heights sorted; dummy '0' for convenience
            int top = 0;                                        // current max height among leftWallHeights
            for (auto w : walls) {
                if (w[1] < 0) {                                 // it's a left wall, insert the height
                    leftWallHeights.insert(-w[1]);
                } else {                                        // it's a right wall, delete the height,
                                                                // then next step(if..) all the second one
                    leftWallHeights.erase(leftWallHeights.find(w[1]));
                }

                if (*leftWallHeights.rbegin() != top) {         // mark a skyline point if top changes
                    ans.push_back({w[0], *leftWallHeights.rbegin()});
                    top = *leftWallHeights.rbegin()};// update the top
                }
            }

            return ans;
    }
};


class Solution {
public:
    void append(vector<vector<int>> &arr, int x,int h){
        int n = arr.size();
        if(n > 0 && arr.back()[1] == h)
            return;
        if(n > 0 && arr.back()[0] == x){
            int maxh = arr.back()[1];
            while(arr.size() > 0 && arr.back()[0] == x){
                maxh = max(maxh, h);
                arr.pop_back();
            }
            arr.push_back({x, maxh});
            return;
        }
        arr.push_back({x,h});
    }
    vector<vector<int>> mergeSkylines(vector<vector<int>> left, vector<vector<int>> right){
        int m = left.size(), n = right.size();
        int i = 0 , j = 0;
        vector<vector<int>> skyline;
        int x1,x2, h1 = 0, h2 = 0, maxh = 0;
        while(i < m && j < n){
            if(left[i][0] < right[j][0]){
                x1 = left[i][0];
                h1 = left[i][1];
                maxh = max(h1,h2);
                append(skyline, x1, maxh);
                i++;
            }else if(left[i][0] > right[j][0]){
                x2 = right[j][0];
                h2 = right[j][1];
                maxh = max(h1,h2);
                append(skyline, x2, maxh);
                j++;
            }else{
                x1 = left[i][0];
                h1 = left[i][1];
                h2 = right[j][1];
                maxh = max(h1,h2);
                append(skyline, x1, maxh);
                i++;
                j++;
            }
            
        }
        
        while(i < m){
            append(skyline, left[i][0], left[i][1]);
            i++;
        }
        
        while(j < n){
            append(skyline, right[j][0], right[j][1]);
            j++;
        }
        
        return skyline;
    }
    vector<vector<int>> helper(vector<vector<int>>& buildings, int low, int high){
        vector<vector<int>> ans;
        if(low > high)
            return ans;
        if(low == high){
            int x = buildings[low][0], y = buildings[low][1], h = buildings[low][2];
            ans.push_back({x,h});
            ans.push_back({y,0});
            return ans;
        }
        int mid = (low + high)/2;
        vector<vector<int>> left = helper(buildings, low, mid);
        vector<vector<int>> right = helper(buildings, mid+1, high);
        ans = mergeSkylines(left,right);
        return ans;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return helper(buildings, 0, buildings.size()-1);
    }
};
