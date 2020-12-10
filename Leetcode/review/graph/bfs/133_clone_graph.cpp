/*******************************************************************
* https://leetcode.com/problems/clone-graph/
* Medium
* 
* Conception: 
*  1. 
*
* Given a reference of a node in a connected undirected graph.
* Return a deep copy (clone) of the graph.
* Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/problems/clone-graph/discuss/42313/C%2B%2B-BFSDFS
*  2. https://leetcode.com/problems/clone-graph/discuss/951970/C%2B%2B-DFS-and-BFS-Approach
*
*******************************************************************/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//BFS
class Solution {
private:
    unordered_map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        Node* copy = new Node(node -> val, {});
        copies[node] = copy;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            int size = q.size();
            Node* curr = q.front();
            q.pop();
            for(auto n : curr->neighbors){
                if(copies.find(n) == copies.end()){
                    copies[n] = new Node(n->val, {});
                    q.push(n);
                }
                copies[curr]->neighbors.push_back(copies[n]);
            }
        }
        
        
        return copy;
    }
};

class Solution {
public:
    Node* helper(Node* node,unordered_map<Node*,Node*> &mp){
        if(node==NULL){
            return NULL;
        }
        Node* clone = new Node(node->val);
        mp[node] = clone;

        for(auto n : node->neighbors){
            if(!mp.count(n)){
                Node* y = helper(n,mp);
                (clone->neighbors).push_back(y);
            } else {
                (clone->neighbors).push_back(mp[n]);
            }
        }
        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node* , Node*> mp;
        return helper(node,mp);
    }
};