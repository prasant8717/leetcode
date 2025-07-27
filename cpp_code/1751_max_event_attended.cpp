class Solution {
private:
    int check(vector<vector<int>>& events, int i, int k,
                vector<vector<int>>& mem) {
        int ret = 0;
        if ((k != 0) && (i != events.size())) {
            if (mem[i][k] != -1)
                ret = mem[i][k];
            else {
                auto it = upper_bound(events.begin() + i, events.end(),
                            events[i][1], [](int end, vector<int>& event) { 
                                return event[0] > end; });
                int j = distance(events.begin(), it);
                int t = events[i][2] + check(events, j, k - 1, mem);
                int u = check(events, i + 1, k, mem);
                if (t > u)
                    mem[i][k] = t;
                else
                    mem[i][k] = u;
                ret = mem[i][k];
            }
        }
        return ret;
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> mem(events.size(), vector<int>(k + 1, -1));
        ranges::sort(events);
        return check(events, 0, k, mem);
    }
};
