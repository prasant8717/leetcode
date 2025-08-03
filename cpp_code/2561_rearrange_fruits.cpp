class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> um;
        for (auto b1 : basket1) {
            um[b1] ++;
        }
        for (auto b2 : basket2) {
            um[b2] --;
        }
        vector<int> v;
        int m = 1 << 30;
        for (auto [t, c] : um) {
            if (c % 2) {
                return -1;
            }
            for (int i = abs(c) / 2; i; -- i) {
                v.push_back(t);
            }
            if (m > t)
                m = t;
        }
        ranges::sort(v);
        int n = v.size();
        long long res = 0;
        int t = (m << 1);
        for (int i = 0; i < n / 2; ++ i) {
            if (t > v[i])
                res += v[i];
            else
                res += t;
        }
        return res;
    }
};
