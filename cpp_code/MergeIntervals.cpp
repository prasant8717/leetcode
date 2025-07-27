class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> vout;
        ranges::sort(intervals);
        for (int i = 0; i < intervals.size(); ++ i) {
            if ((vout.empty() != 0) || (vout.back()[1] < intervals[i][0]))
                vout.push_back(intervals[i]);
            else
                vout.back()[1] = max(vout.back()[1], intervals[i][1]);
        }
        return vout;
    }
};
