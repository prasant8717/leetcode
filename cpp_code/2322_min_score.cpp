class Solution {
private:
    int dfs(vector<int>& nums, vector<vector<int>>& vg, int i, int fa) {
        int res = nums[i];
        for (int j = 0; j < vg[i].size(); ++ j) {
            int t = vg[i][j];
            if (t != fa) {
                res ^= dfs(nums, vg, t, i);
            }
        }
        return res;
    }

    int dfs2(vector<int>& nums, vector<vector<int>>& vg,
             int i, int fa, int s, int s1, int& res) {
        int r = nums[i];
        for (int j = 0; j < vg[i].size(); ++ j) {
            int t = vg[i][j];
            if (t != fa) {
                int s2 = dfs2(nums, vg, t, i, s, s1, res);
                r ^= s2;
                int mx = max({s ^ s1, s2, s1 ^ s2});
                int mn = min({s ^ s1, s2, s1 ^ s2});
                res = min(res, mx - mn);
            }
        }
        return r;
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> vg(n);
        for (int i = 0; i < edges.size(); ++ i) {
            int a = edges[i][0];
            int b = edges[i][1];
            vg[a].push_back(b);
            vg[b].push_back(a);
        }
        int s = 0;
        int s1 = 0;
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); ++ i) {
            s ^= nums[i];
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < vg[i].size(); ++ j) {
                int t = vg[i][j];
                s1 = dfs(nums, vg, i, t);
                dfs2(nums, vg, i, t, s, s1, res);
            }
        }
        return res;
    }
};
