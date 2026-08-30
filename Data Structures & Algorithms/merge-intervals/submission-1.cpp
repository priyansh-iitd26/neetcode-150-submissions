class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;
        if(intervals[0][1] >= intervals[1][0]){
            int min_start = min(intervals[0][0], intervals[1][0]);
            int max_end = max(intervals[0][1], intervals[1][1]);
            mergedIntervals.push_back({min_start, max_end});
        }
        else{
            mergedIntervals.push_back(intervals[0]);
            mergedIntervals.push_back(intervals[1]);
        }
        
        for(int i = 2; i < n; i++){
            // mergedIntervals.back() & intervals[i]
            if(mergedIntervals.back()[1] >= intervals[i][0]){
                int min_start = min(mergedIntervals.back()[0], intervals[i][0]);
                int max_end = max(mergedIntervals.back()[1], intervals[i][1]);
                mergedIntervals.pop_back();
                mergedIntervals.push_back({min_start, max_end});
            }
            else{
                mergedIntervals.push_back(intervals[i]);
            }
        }
        return mergedIntervals;
    }
};
