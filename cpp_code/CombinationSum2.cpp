class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cmb;
        function<void(int, int)> combine = [&](int i, int s) {
            if (s == 0) {
                res.emplace_back(cmb);
                return;
            }
            if ((i >= candidates.size()) || (s < candidates[i])) {
                return;
            }
            for (int j = i; j < candidates.size(); ++ j) {
                if ((j > i) && (candidates[j] == candidates[j - 1])) {
                    continue;
                }
                cmb.emplace_back(candidates[j]);
                combine(j + 1, s - candidates[j]);
                cmb.pop_back();
            }
        };
        combine(0, target);
        return res;
    }
};
