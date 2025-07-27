class Solution {
public:
    bool validate(vector<int>& n,
               vector<vector<int>>& q,
               int k) {
        vector<int> v(n.size() + 1, 0);
        for (int i = 0; i < k; ++ i) {
            v[q[i][0]] += q[i][2];
            v[q[i][1] + 1] -= q[i][2];
        }
        int t = 0;
        for (int i = 0; i < n.size(); ++ i) {
            t += v[i];
            if (n[i] > t)
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int l = 0;
        int r = q + 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (validate(nums, queries, m) == true)
                r = m;
            else
                l = m + 1;
        }
        return (l > q) ? -1 : l;
    }
};
