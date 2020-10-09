/*******************************************************************
* https://leetcode.com/problems/campus-bikes/
* Medium
* 
* Conception: 
*  1. 
*
* On a campus represented as a 2D grid,
* there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.
*
* Our goal is to assign a bike to each worker.
* Among the available bikes and workers,
* we choose the (worker, bike) pair with the shortest Manhattan distance between each other,
* and assign the bike to that worker. (If there are multiple (worker, bike) pairs with the same shortest Manhattan distance,
* we choose the pair with the smallest worker index;
* if there are multiple ways to do that, we choose the pair with the smallest bike index).
* We repeat this process until there are no available workers.
*
* The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
*
* Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that the i-th worker is assigned to.
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
    struct Distance {
        int dist;
        int idx_w;
        int idx_b;
    };
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> assignment(workers.size());
        vector<int> assigned_w(workers.size(), 0);
        vector<int> assigned_b(bikes.size(), 0);
        vector<Distance> distances(workers.size() * bikes.size());
        
        //calculate the distances
        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                distances[i * bikes.size() + j].dist = getDistance(workers, bikes, i, j);
                distances[i * bikes.size() + j].idx_w = i;
                distances[i * bikes.size() + j].idx_b = j;
            }
        }
        
        //sort the distances
        std::sort(distances.begin(), distances.end(), [](const Distance& a, const Distance& b) {
            if (a.dist == b.dist) {
                return a.idx_w == b.idx_w ? a.idx_b < b.idx_b : a.idx_w < b.idx_w;
            }
            return a.dist < b.dist;
        });
        
        //assign bike to workers
        for (const auto &dist : distances) {
            if (!assigned_w[dist.idx_w] && !assigned_b[dist.idx_b]) {
                assignment[dist.idx_w] = dist.idx_b;
                assigned_w[dist.idx_w] = 1;
                assigned_b[dist.idx_b] = 1;
            }
        }
        
        return assignment;
    }
    
    int getDistance(const vector<vector<int>>& workers, const vector<vector<int>>& bikes, int idx_w, int idx_b) {
        return abs(workers[idx_w][0] - bikes[idx_b][0]) + abs(workers[idx_w][1] - bikes[idx_b][1]);
    }
};