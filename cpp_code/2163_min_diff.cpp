class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        using ll = long long;
        ll s = 0;
        int m = nums.size();
        vector<ll> vl1(m + 1);
        priority_queue<int> pq1;
        int n = m / 3;
        for (int i = 1; i <= (n << 1); ++ i) {
            int t = nums[i - 1];
            s += t;
            pq1.push(t);
            if (pq1.size() > n) {
                s -= pq1.top();
                pq1.pop();
            }
            vl1[i] = s;
        }
        s = 0;
        vector<ll> vl2(m + 1);
        priority_queue<int, vector<int>, greater<int>> pq2;
        for (int i = m; i > n; -- i) {
            int t = nums[i - 1];
            s += t;
            pq2.push(t);
            if (pq2.size() > n) {
                s -= pq2.top();
                pq2.pop();
            }
            vl2[i] = s;
        }
        ll res = 1e18;
        for (int i = n; i <= (n << 1); ++ i) {
            ll t = vl1[i] - vl2[i + 1];
            if (res > t)
                res = t;
        }
        return res;
    }
};
