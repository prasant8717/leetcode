class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> v(n - 1);
        for (int i = 0; i < n - 1; ++ i)
            v[i] = weights[i] + weights[i + 1];
        ranges::sort(v);
        long long res = 0;
        for (int i = 0; i < k - 1; ++ i) {
            res -= v[i];
            res += v[n - 2 - i];
        }
        return res;
    }
};
