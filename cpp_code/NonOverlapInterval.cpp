class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
                [](const auto& x, const auto& y) {
            return x[1] < y[1];
        });
        int cnt = 0;
        int tt = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (tt <= intervals[i][0]) {
                tt = intervals[i][1];
            } else {
                ++cnt;
            }
        }
        return cnt;
    }
};
