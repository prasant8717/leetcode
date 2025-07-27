class Solution {
private:
    int predict(vector<vector<int>>& v, vector<int>& n, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (v[i][j] != 0) {
            return v[i][j];
        }
        int t = n[i] - predict(v, n, i + 1, j);
        int u = n[j] - predict(v, n, i, j - 1);
        if (t < u)
            v[i][j] = u;
        else
            v[i][j] = t;
        return v[i][j];
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vv(n, vector<int>(n));
        bool sts = false;
        if (predict(vv, nums, 0, n - 1) >= 0)
            sts = true;
        return sts;
    }
};
