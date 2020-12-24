/*******************************************************************
* https://leetcode.com/problems/find-median-from-data-stream/
* Hard
* 
* Conception: 
*  1.
*
* Median is the middle value in an ordered integer list.
* If the size of the list is even, there is no middle value.
* So the median is the mean of the two middle value.
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class MedianFinder {
public:
    vector<double>number;
    int i = 0;
    // Adds a number into the data structure.
    void addNum(int num) {
        int l = 0, h = number.size()-1;
        while(l <= h){
            int mid = (l + h)/2;
            if(num > number[mid]){
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        number.insert(number.begin()+l,(double)num);
        i++;
    }

    // Returns the median of current data stream
    double findMedian() {
        if(i == 0) return 0;
        if( i%2 == 0) return (number[i/2] + number[(i/2)-1])/2.0;

        return number[i/2];
        
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */