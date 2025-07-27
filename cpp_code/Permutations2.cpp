class Solution {
public:
    void fill(vector<int>& n, vector<bool>& b, vector<int>& c, vector<vector<int>>& o) {
        if (c.size() == n.size()) {
            o.push_back(c);
            return;
        }
        for (int i = 0; i < n.size(); ++ i) {
            if (b[i] == true) {
                continue;
            }
            if (i && (n[i] == n[i - 1]) && (b[i - 1] == false))
                continue;
            b[i] = true;
            c.push_back(n[i]);
            fill(n, b, c, o);
            c.pop_back();
            b[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> vout;
        vector<bool> t(nums.size());
        vector<int> cur;
        ranges::sort(nums);
        fill(nums, t, cur, vout);
        return vout;
    }
};
