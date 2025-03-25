class Solution {
 private:
    int count(vector<pair<int, int>>& vp) {
        ranges::sort(vp);
        int c = 0;
        int p = 0;
        for (int i = 0; i < vp.size(); ++ i) {
            pair<int, int> pt = vp[i];
            if (pt.first < p) {
                if (p < pt.second)
                    p = pt.second;
            } else {
                p = pt.second;
                ++ c;
            }
        }
        return c;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> vx;
        vector<pair<int, int>> vy;
        for (int i = 0; i < rectangles.size(); ++ i) {
            int sx = rectangles[i][0];
            int sy = rectangles[i][1];
            int ex = rectangles[i][2];
            int ey = rectangles[i][3];
            vx.emplace_back(sx, ex);
            vy.emplace_back(sy, ey);
        }
        int res = count(vx);
        int t = count(vy);
        if (res < t)
            res = t;
        return res >= 3;
    }
};
