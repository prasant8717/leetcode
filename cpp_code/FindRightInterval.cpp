class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < sz; ++i) {
            vp.emplace_back(intervals[i][0], i);
        }
        ranges::sort(vp);
        vector<int> vout;
        for (int i = 0; i < sz; ++ i) {
            int j = lower_bound(vp.begin(), vp.end(), make_pair(intervals[i][1], -1)) - vp.begin();
            vout.push_back(j == sz ? -1 : vp[j].second);
        }
        return vout;
    }
};
