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


//Heap: slower
class Solution {
private:
    struct comp{
        bool operator()(const pair<vector<int>, float>& p1,
                        const pair<vector<int>, float>& p2){
            return p1.second < p2.second;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<vector<int>, float>, vector<pair<vector<int>, float>>, comp> maxHeap;
        for(auto& p:points){
            float dist = sqrt(pow(p[0], 2) + pow(p[1], 2));
            maxHeap.push(make_pair(p, dist));
            if(maxHeap.size() > K){
                maxHeap.pop();
            }
        }

        // Put all points in maxHeap into the result
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++){
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return ans;
                
    }
};