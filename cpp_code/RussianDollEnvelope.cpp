class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return (e1[0] < e2[0]) ||
                   ((e1[0] == e2[0]) && (e1[1] > e2[1]));
        });
        int r = envelopes.size();
        vector<int> v;
        v.push_back(envelopes[0][1]);
        for (int i = 1; i < r; ++ i) {
            int n = envelopes[i][1];
            if (n > v[v.size() - 1])
                v.push_back(n);
            else {
                int idx = lower_bound(v.begin(), v.end(), n)
                            - v.begin();
                if (idx == v.size())
                    idx = 0;
                v[idx] = n;
            }
        }
        return v.size();
    }
};
