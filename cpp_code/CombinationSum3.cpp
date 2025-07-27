class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> out;
        vector<int> tmp;
        function<void(int, int)> dfs = [&](int st, int sum) {
            if (sum == 0 && tmp.size() == k) {
                out.emplace_back(tmp);
                return;
            }
            if (st > 9 || st > sum || tmp.size() >= k) {
                return;
            }
            tmp.emplace_back(st);
            dfs(st + 1, sum - st);
            tmp.pop_back();
            dfs(st + 1, sum);
        };
        dfs(1, n);
        return out;        
    }
};
