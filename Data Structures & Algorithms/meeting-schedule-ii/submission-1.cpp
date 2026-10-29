/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;

        for(auto &interval : intervals){
            int begin = interval.start;
            int finish = interval.end;

            if(pq.empty() || begin < pq.top()){
                ans++;
                pq.push(finish);
            }

            else{
                pq.pop();
                pq.push(finish);
            }
        }
        
        return ans;
    }
};
