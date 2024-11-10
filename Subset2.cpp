class Solution {
public:
    void subset(vector<int>& nums, int c, int l, vector<int>& s, vector<vector<int>>& o) {
        o.push_back(s);
        for (int i = c; i < l; ++ i) {
            if ((i > c) && (nums[i] == nums[i - 1]))
                continue;
            s.push_back(nums[i]);
            subset(nums, i + 1, l, s, o);
            s.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> sel;
        ranges::sort(nums);
        subset(nums, 0, nums.size(), sel, out);
        return out;
    }
};
