/*******************************************************************
* https://leetcode.com/problems/lru-cache/
* Medium
* 
* Conception: 
*  1. 
*
* Design and implement a data structure for Least Recently Used (LRU) cache.
* It should support the following operations: get and put.
*
* get(key) - Get the value (will always be positive) of the key
*   if the key exists in the cache, otherwise return -1.
* put(key, value) - Set or insert the value if the key is not already present.
*   When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*
* The cache is initialized with a positive capacity.
*
*
* Follow up:
* Could you do both operations in O(1) time complexity?
*
* Example:
*
* Methods:
*  1. unordered_map*2 + queue
*  2. doule linkedlist + unordered_map
*
* References:
*  1. Linedlist replaced queueu: https://leetcode.com/problems/lru-cache/discuss/309691/DOUBLY-LINKED-LIST-%2B-HASHMAP-java-solution
*  2. https://bhrigu.me/blog/2017/01/22/lru-cache-c-plus-plus-implementation/
*  3. https://blog.techbridge.cc/2019/04/06/how-to-use-python-implement-least-recently-used/
*  4. https://www.youtube.com/watch?v=q1Njd3NWvlY&t=588s
*
*******************************************************************/
class LRUCache {
private:
    unordered_map <int,int> saveTime; //key,time
    unordered_map <int,int> saveVal; //key,value
    queue<int> manageKey;
    int capacity;

public:
    LRUCache(int capacity): capacity(capacity) {

    }
    
    int get(int key) {
        if(saveVal.count(key)){
            manageKey.push(key);
            saveTime[key]++;
            return saveVal[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!saveTime.count(key)){ //not exist
            saveTime[key] = 1;
            saveVal[key] = value;
            manageKey.push(key);
        }else{
            saveTime[key]++;
            saveVal[key] = value;
            manageKey.push(key);
        }
        
        while(saveTime.size() > capacity){
            int val = manageKey.front();
            manageKey.pop();
            saveTime[val]--;
            if(saveTime[val] == 0){
                saveTime.erase(val);
                saveVal.erase(val);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */