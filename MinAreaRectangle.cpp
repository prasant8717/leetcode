class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> mp;
        for (int i = 0; i < points.size(); ++ i) {
            int a = points[i][0];
            int b = points[i][1];
            mp[a].emplace_back(b);
        }
        unordered_map<int, int> um;
        int res = 1 << 30;
        for (auto& [x, y] : mp) {
            ranges::sort(y);
            int n = y.size();
            for (int i = 0; i < n; ++ i) {
                int y1 = y[i];
                for (int j = i + 1; j < n; ++ j) {
                    int y2 = y[j];
                    int t = y1 * 40001 + y2;
                    if (um.count(t)) {
                        res = min(res, (x - um[t]) * (y2 - y1));
                    }
                    um[t] = x;
                }
            }
        }
        return res == 1 << 30 ? 0 : res;
    }
};
