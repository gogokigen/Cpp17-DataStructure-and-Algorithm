/*******************************************************************
* https://leetcode.com/problems/kth-largest-element-in-a-stream/
* Easy
* 
* Conception: 
*  1. 
*
* Design a class to find the kth largest element in a stream.
* Note that it is the kth largest element in the sorted order,
* not the kth distinct element.
*
* Implement KthLargest class:
*    KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
*    int add(int val) Returns the element representing the kth largest element in the stream.
*
*
* Example:
* 
* Key:
*  1. use Heap (C++: priority_queue)
*
* References:
*  1. https://blog.techbridge.cc/2020/04/12/leetcode-%E5%88%B7%E9%A1%8C-pattern-top-k-elements/
*
*******************************************************************/
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K = 0;
public:
    KthLargest(int k, vector<int>& nums) {

        K = k;
        for(int& i : nums){
            add(i);
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if(minHeap.size() > K){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
