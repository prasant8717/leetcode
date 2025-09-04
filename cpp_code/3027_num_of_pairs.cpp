class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;
        ranges::sort(points, ranges::less{}, [](vector<int>& v) {
            return pair<int, int>{v[0], -v[1]};
        });
        for (int i = 0; i < points.size(); ++ i) {
            int m = INT_MIN;
            for (int j = i + 1; j < points.size(); ++ j)
                if ((points[i][1] >= points[j][1]) && (points[j][1] > m)) {
                    ++ res;
                    m = points[j][1];
                }
        }
        return res;
    }
};
