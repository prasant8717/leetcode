class Solution {
private:
    int prime(int n) {
        unordered_set<int> us;
        int i = 2;
        while (i <= (n / i)) {
            while ((n % i) == 0) {
                us.insert(i);
                n /= i;
            }
            ++ i;
        }
        if (n > 1)
            us.insert(n);
        return us.size();
    }

    long long vpow(long long l, int n) {
        int m = 1e9 + 7;
        long long res = 1;
        for (; n; n >>= 1) {
            if (n & 1)
                res = (res * l) % m;
            l = (l * l) % m;
        }
        return res;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<tuple<int, int, int>> vt(n);
        for (int i = 0; i < n; ++ i)
            vt[i] = {i, prime(nums[i]), nums[i]};
        vector<int> vl(n, -1);
        vector<int> vr(n, n);
        stack<int> stk;
        for (auto [i, f, _] : vt) {
            while ((stk.empty() == 0) && (get<1>(vt[stk.top()]) < f))
                stk.pop();
            if (stk.empty() == 0)
                vl[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; -- i) {
            int f = get<1>(vt[i]);
            while ((stk.empty() == 0) && (get<1>(vt[stk.top()]) <= f))
                stk.pop();
            if (stk.empty() == 0)
                vr[i] = stk.top();
            stk.push(i);
        }
        ranges::sort(vt, [](auto& l, auto& r) {
            return get<2>(r) < get<2>(l);
        });
        long long res = 1;
        int m = 1e9 + 7;
        for (auto [i, _, x] : vt) {
            int l = vl[i];
            int r = vr[i];
            long long c = 1LL * (i - l) * (r - i);
            if (c <= k) {
                res = (res * vpow(x, c)) % m;
                k -= c;
            } else {
                res = (res * vpow(x, k)) % m;
                break;
            }
        }
        return res;
    }
};
