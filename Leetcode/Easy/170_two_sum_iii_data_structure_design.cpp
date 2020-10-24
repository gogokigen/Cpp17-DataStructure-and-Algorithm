/*******************************************************************
* https://leetcode.com/problems/two-sum-iii-data-structure-design/
* Easy
* 
* Conception: 
*  1. 
*
* Design a data structure that accepts a stream of integers
* and checks if it has a pair of integers that sum up to a particular value.
*
* Implement the TwoSum class:
*    TwoSum() Initializes the TwoSum object, with an empty array initially.
*    void add(int number) Adds number to the data structure.
*    boolean find(int value) Returns true if there exists any pair of numbers
*      whose sum is equal to value, otherwise, it returns false.
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
class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> mp ;
    TwoSum() {
    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        mp[number]++ ;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {

        for(auto it = mp.begin() ; it != mp.end() ; it++){
            long n1 = it->first ;
            long n2 = (long)value - n1 ;
            if (mp.count(n2)){
                // For cases like 2+2=4, need 2 2s in the map
                if ( (n1 != n2 && mp[n2]>=1) || ((n1 == n2) && mp[n2]>=2) )
                    return true ;
            }
        }
        return false ;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */