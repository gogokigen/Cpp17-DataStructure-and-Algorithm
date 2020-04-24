/*******************************************************************
* https://leetcode.com/problems/lfu-cache/
* Hard
* 
* Conception: 
*  1. 
*
* Design and implement a data structure for Least Frequently Used (LFU) cache.
* It should support the following operations: get and put.
*
*
* Follow up:
* Could you do both operations in O(1) time complexity?
*
* Example:
*
* Methods:
*  1. 
*
* References:
*  1. https://www.youtube.com/watch?v=MCTN3MM8vHA
*  2. https://www.geeksforgeeks.org/least-frequently-used-lfu-cache-implementation/
*
*******************************************************************/
class LFUCache {
private:
    map <int, int> mapKeyFreq; // key, freq
    map<int, deque<int>> mapFreqKey; // freq to key(as a queue)
    unordered_map <int,int> mapKeyVal; //key,value
    int capacity;

public:
    LFUCache(int capacity):capacity(capacity) {
    }
    
    int get(int key) {
        if(mapKeyVal.count(key)){
            auto u = mapKeyFreq[key];
            mapFreqKey[u+1].push_back(key);
            mapKeyFreq[key] = u+1;
            return mapKeyVal[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        //if(mapKeyVal.find(key) != mapKeyVal.end()) {
        if(mapKeyVal.count(key)){//exist
            auto u = mapKeyFreq[key];
            mapFreqKey[u+1].push_back(key);
            mapKeyFreq[key] = u + 1;
            mapKeyVal[key] = value;
        }else{
            bool remove = false;
            if(mapKeyVal.size() >= capacity){
                //full
                for(auto& i:mapFreqKey){
                    while(!i.second.empty()) {
                        auto keyOfMinFreq = i.second.front();
                        i.second.pop_front();
                        if(i.first == mapKeyFreq[keyOfMinFreq]){
                            remove = true;
                            mapKeyFreq.erase(keyOfMinFreq);
                            mapKeyVal.erase(keyOfMinFreq);
                            break;
                        }
                    }
                    if(remove) break;
                }
            }
            //add
            mapKeyVal[key] = value;
            mapKeyFreq[key] = 0;
            mapFreqKey[0].push_back(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */