class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size() - 1; ++ i) {
            int t1 = abs(points[i + 1][0] - points[i][0]);
            int t2 = abs(points[i + 1][1] - points[i][1]);
            if (t1 < t2)
                res += t2;
            else
                res += t1;
        }
        return res;
    }
};
