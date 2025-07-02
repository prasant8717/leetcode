class BIT {
public:
    BIT(int t) : i(t), v(t + 1) {}
    void update(int t, int a) {
        while (t <= i) {
            v[t] += a;
            t += t & -t;
        }
    }
    int query(int t) {
        int a = 0;
        while (t) {
            a += v[t];
            t -= t & -t;
        }
        return a;
    }

private:
    int i;
    vector<int> v;
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        using ll = long long;
        int n = nums.size();
        vector<ll> vs(n + 1);
        for (int i = 0; i < n; ++ i) {
            vs[i + 1] = vs[i] + nums[i];
        }
        vector<ll> va((n + 1) * 3);
        int j = 0;
        for (int i = 0; i <= n; ++ i) {
            va[j] = vs[i];
            va[j + 1] = vs[i] - lower;
            va[j + 2] = vs[i] - upper;
            j += 3;
        }
        ranges::sort(va);
        int m = unique(va.begin(), va.end()) - va.begin();
        BIT tr(m);
        int res = 0;
        for (int i = 0; i <= n; ++ i) {
            int l = lower_bound(va.begin(), va.begin() + m, vs[i] - upper) - va.begin() + 1;
            int r = lower_bound(va.begin(), va.begin() + m, vs[i] - lower) - va.begin() + 1;
            res += tr.query(r) - tr.query(l - 1);
            tr.update(lower_bound(va.begin(), va.begin() + m, vs[i]) - va.begin() + 1, 1);
        }
        return res;
    }
};
