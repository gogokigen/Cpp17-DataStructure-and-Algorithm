/*******************************************************************
* First Unique Number
* Medium
* 
* Conception: 
*  1. like LRU
*
* You have a queue of integers, you need to retrieve the first unique integer in the queue.
*
*   FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
*   int showFirstUnique() returns the value of the first unique integer of the queue,
*        and returns -1 if there is no such integer.
*   void add(int value) insert value to the queue.
*
* Reference:
*  https://www.youtube.com/watch?v=eky43Oe8qLI 
*
*******************************************************************/
class FirstUnique {
private:
    list<int> cache; //val
    unordered_map<int, list<int>::iterator> _m; //val
public:
    FirstUnique(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        if(cache.size() > 0){
            return *cache.begin();
        }
        return -1;
    }
    
    void add(int value) {
        if(_m.find(value) != _m.end()){//exist
            list<int>::iterator itr = _m[value];
            if(itr != cache.end()){ // in list
                cache.erase(itr); //remove from list
                _m[value] = cache.end(); // remove from map
            }
        }else{
            cache.push_back(value);
            list<int>::iterator itr = cache.end();
            itr--;
            _m[value] = itr;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */