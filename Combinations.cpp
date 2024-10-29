class Solution {
public:
    void get_combination(vector<vector<int>>& out, int n, int k, int sz, vector<int>&& comb) {
        if (comb.size() == k) {
            out.push_back(comb);
            return;
        }
        for (int i = sz; i <= n; ++i) {
            comb.push_back(i);
            get_combination(out, n, k, i + 1, std::move(comb));
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vout;
        get_combination(vout, n, k, 1, {});
        return vout;
    }
};
