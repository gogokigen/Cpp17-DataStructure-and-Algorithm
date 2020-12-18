/*******************************************************************
* https://leetcode.com/problems/my-calendar-ii/
* Medium
* 
* Conception: 
*  1.
*
* Implement a MyCalendarTwo class to store your events.
* A new event can be added if adding the event will not cause a triple booking.
* Your class will have one method, book(int start, int end).
* Formally, this represents a booking on the half open interval [start, end),
* the range of real numbers x such that start <= x < end.
*
* A triple booking happens when three events have some non-empty intersection
* (ie., there is some time that is common to all 3 events.)
*
* For each call to the method MyCalendar.book,
* return true if the event can be added to the calendar successfully without causing a triple booking.
* Otherwise, return false and do not add the event to the calendar.
* Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. https://leetcode.com/problems/my-calendar-ii/discuss/323479/Simple-C%2B%2B-Solution-using-built-in-map-(Same-as-253.-Meeting-Rooms-II)
*  2. https://leetcode.com/problems/my-calendar-ii/discuss/109519/JavaC%2B%2B-Clean-Code-with-Explanation
*
*******************************************************************/
class MyCalendarTwo {
public:
    map<int, int> mp; // key: time; val: +1 if start, -1 if end
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int booked = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            booked += it->second;
            if (booked == 3) {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

class MyCalendarTwo {
    vector<pair<int, int>> books;
public:
    bool book(int start, int end) {
        MyCalendar overlaps;
        for (pair<int, int> p : books) {
            if (max(p.first, start) < min(end, p.second)) { // overlap exist
                pair<int, int> overlapped = getOverlap(p.first, p.second, start, end);
                if (!overlaps.book(overlapped.first, overlapped.second)) return false; // overlaps overlapped
            }
        }
        books.push_back({ start, end });
        return true;
    }

    pair<int, int> getOverlap(int s0, int e0, int s1, int e1) {
        return { max(s0, s1), min(e0, e1)};
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
 