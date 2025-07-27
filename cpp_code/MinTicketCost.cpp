class Solution {
public:
    int totCost (int d, int n, vector<int>& vd, vector<int>& c, vector<int>& v, vector<int>& vc) {
        if (d >= n)
            return 0;
        if (v[d] != 0)
            return v[d];
        v[d] = INT_MAX;
        for (int i = 0; i < vc.size(); ++ i) {
            int j = lower_bound(vd.begin(), vd.end(), vd[d] + vc[i]) - vd.begin();
            long long t = (long long)c[i] + totCost(j, n, vd, c, v, vc);
            if (v[d] > t)
                v[d] = t;
        }
        return v[d];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int d = days.size();
        vector<int> v(d);
        for (int i = 0; i < d; ++ i)
            v[i] = 0;
        vector<int> vc(3);
        vc[0] = 1;
        vc[1] = 7;
        vc[2] = 30;
        return totCost(0, d, days, costs, v, vc);
    }
};
