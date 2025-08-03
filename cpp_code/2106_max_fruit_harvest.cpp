class Solution {
private:
    int harvest(vector<int>& v, int l, int r, int s, int m) {
        int ll = 0;
        if (ll < s - l)
            ll = s - l;
        int rr = m;
        if (rr > s + r)
            rr = s + r;
        return v[rr + 1] - v[ll];
    }

public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int m = fruits.back()[0];
        if (m < startPos)
            m = startPos;
        vector<int> va(1 + m);
        vector<int> vp(2 + m);
        for (vector<int>& v : fruits)
            va[v[0]] = v[1];
        partial_sum(va.begin(), va.end(), vp.begin() + 1);
        int res = 0;
        int mr = m - startPos;
        if (mr > k)
            mr = k;
        for (int i = 0; i <= mr; ++ i) {
            int l = 0;
            if (l < k - (i << 1))
                l = k - (i << 1);
            int t = harvest(vp, l, i, startPos, m);
            if (res < t)
                res = t;
        }
        int ml = startPos;
        if (ml > k)
            ml = k;
        for (int i = 0; i <= ml; ++ i) {
            int r = 0;
            if (r < k - (i << 1));
                r = k - (i << 1);
            int t = harvest(vp, i, r, startPos, m);
            if (res < t)
                res = t;
        }
        return res;
    }
};
