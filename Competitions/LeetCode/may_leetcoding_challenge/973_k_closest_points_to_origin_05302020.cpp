/*******************************************************************
* https://leetcode.com/problems/k-closest-points-to-origin/
* Medium
* 
* Conception: 
*  1. 
*
* We have a list of points on the plane.
* Find the K closest points to the origin (0, 0).
*
* (Here, the distance between two points on a plane is the Euclidean distance.)
*
* You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
*
* Key:
*
* Explanation:
*
* References:
*  1. https://www.youtube.com/watch?v=zWiB3RGa-vo
*
*******************************************************************/
class Solution {
private:
    int dist(vector<int>& point){
        return (point[0]*point[0]+point[1]*point[1]);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //calculate dists of all
        int pointsSize = points.size();
        vector<int> dists(pointsSize);
        for(int i = 0; i < pointsSize; i++){
            dists[i] = dist(points[i]);
        }
        sort(dists.begin(),dists.end());
        int targetDist = dists[K-1];
        int j = 0;
        vector<vector<int>> ans(K,vector<int> (2));
        for(int i = 0; i < pointsSize; i++){
            if(dist(points[i]) <= targetDist){
                ans[j][0] = points[i][0];
                ans[j][1] = points[i][1];
                j++;
            }
        }
        return ans;
                
    }
};