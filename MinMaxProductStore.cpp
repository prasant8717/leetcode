class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = 1e5;
        while (l < r) {
            int m = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < quantities.size(); ++ i) {
                cnt += (quantities[i] + m - 1) / m;
            }
            if (cnt <= n)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
