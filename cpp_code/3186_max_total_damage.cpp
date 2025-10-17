class Solution {
private:
    vector<int> iterate(unordered_map<int, int>& um) {
        vector<int> v;
        for (auto& [k, _] : um)
            v.push_back(k);
        ranges::sort(v);
        return v;
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> um;
        for (int t : power)
            ++ um[t];
        vector<int> v = iterate(um);
        int n = v.size();
        vector<vector<long long>> vv(n, vector<long long>(2));
        for (int i = 0; i < n; ++ i) {
            long long t = v[i];
            if (i == 0) {
                vv[0][0] = 0;
                vv[0][1] = t * um[t];
                continue;
            }
            vv[i][0] = ranges::max(vv[i - 1]);
            vv[i][1] = t * um[t];
            if ((i >= 1) && (v[i - 1] != t - 1) &&
                (v[i - 1] != t - 2)) {
                vv[i][1] += max(vv[i - 1][0], vv[i - 1][1]);
            } else if ((i >= 2) && (v[i - 2] != t - 2)) {
                vv[i][1] += max(vv[i - 2][0], vv[i - 2][1]);
            } else if (i >= 3) {
                vv[i][1] += max(vv[i - 3][0], vv[i - 3][1]);
            }
        }
        return ranges::max(vv.back());
    }
};
