class Solution {
public:
    void get_comb(vector<int>& c, int p, int s, int t, vector<vector<int>>& o, vector<int> sel) {
        if (s > t) {
            return;
        }
        if (p == c.size()) {
            return;
        }
        if (s == t) {
            o.push_back(sel);
            return;
        }
        sel.push_back(c[p]);
        get_comb(c, p, s + c[p], t, o, sel);
        sel.pop_back();
        get_comb(c, p + 1, s, t, o, sel);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vout;
        get_comb(candidates, 0, 0, target, vout, {});
        return vout;
    }
};
