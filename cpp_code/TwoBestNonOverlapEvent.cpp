class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        ranges::sort(events);
        int sum = 0;
        vector<int> v(events.size() + 1);
        for (int i = events.size() - 1; i >= 0; -- i) {
            if (v[i + 1] < events[i][2])
                v[i] = events[i][2];
            else
                v[i] = v[i + 1];
        }
        for (int i = 0; i < events.size(); ++ i) {
            int l = 0;
            int r = events.size();
            while (l < r) {
                int m = (l + r) >> 1;
                if (events[m][0] > events[i][1])
                    r = m;
                else
                    l = m + 1;
            }
            int t = events[i][2];
            if (l < events.size())
                t = t + v[l];
            if (sum < t)
                sum = t;
        }
        return sum;
    }
};
