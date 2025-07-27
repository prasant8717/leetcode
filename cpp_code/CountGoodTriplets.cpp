class BITr {
public:
    int n;
    vector<int> v;
    BITr(int a)
        : n(a)
        , v(a + 1) {}
    void update(int t, int d) {
        while (t <= n) {
            v[t] += d;
            t += lowbit(t);
        }
    }
    int query(int t) {
        int a = 0;
        while (t > 0) {
            a += v[t];
            t -= lowbit(t);
        }
        return a;
    }

    int lowbit(int t) {
        return t & -t;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> v(n);
        for (int i = 0; i < n; ++ i)
            v[nums2[i]] = i + 1;
        BITr* tr = new BITr(n);
        long long res = 0;
        for (int i = 0; i < n; ++ i) {
            int p = v[nums1[i]];
            int l = tr->query(p);
            int r = n - p - (tr->query(n) - tr->query(p));
            res += 1ll * l * r;
            tr->update(p, 1);
        }
        return res;        
    }
};
