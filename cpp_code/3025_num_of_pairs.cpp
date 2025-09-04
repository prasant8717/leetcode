class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        ranges::sort(points, [](vector<int>& v1, vector<int>& v2) {
            return (v1[0] < v2[0]) || ((v1[0] == v2[0]) && (v1[1] > v2[1]));
        });
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; ++ i) {
            int t1 = points[i][1];
            int m = INT_MIN;
            for (int j = i + 1; j < n; ++ j) {
                int t2 = points[j][1];
                if ((m < t2) && (t2 <= t1)) {
                    m = t2;
                    ++ res;
                }
            }
        }
        return res;
    }
};
