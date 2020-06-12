/*******************************************************************
* https://leetcode.com/problems/insert-delete-getrandom-o1/
* Medium
* 
* Conception: 
*  1. 
*
* Design a data structure that supports all following operations in average O(1) time.
*
*    insert(val): Inserts an item val to the set if not already present.
*    remove(val): Removes an item val from the set if present.
*    getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
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
//fastest
class RandomizedSet {
public:
    vector<int> tbl;
    unordered_map<int, int> cache; //val,position
    int position = 0;
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(cache.count(val)){
                return false;
        }
        cache[val] = position;
        position++;
        tbl.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(cache.count(val)){
            int index = cache[val];
            int last = tbl.back();
            tbl[index] = last; // last to replace the val (=tbl[index] ---> tbl[cache[val]] = tbl.back()
            cache[last] = index;// cache[last] = cache[val] ---> {tbl.back(), cache[val]}
            tbl.pop_back();
            
            cache.erase(val); // cache[val] 
            position--;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return tbl[rand()%tbl.size()];
    }
};

// ok
class RandomizedSet {
public:
    //vector<int> tbl;
    unordered_set<int> cache; //val,position

    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return (cache.insert(val)).second;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return cache.erase(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return *next(cache.begin(),rand()%cache.size());
    }
};




// Not O(1)
class RandomizedSet {
public:
    vector<int> tbl;
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        for(int& i : tbl){
            if( i == val){
                return false;
            }
        }
        tbl.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        for(int i = 0; i < tbl.size(); i++){
            if(tbl[i] == val){
                tbl.erase(tbl.begin() + i);
                return true;
            }
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return tbl[rand()%tbl.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */