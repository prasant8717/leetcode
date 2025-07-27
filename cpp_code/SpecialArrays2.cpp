class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int l = nums.size();
        vector<int> v(l);
        iota(v.begin(), v.end(), 0);
        for (int i = 0; i < l - 1; ++ i) {
            if ((nums[i] % 2) != (nums[i + 1] % 2)) {
                v[i + 1] = v[i];
            }
        }
        vector<bool> out;
        for (int i = 0; i < queries.size(); ++ i) {
            out.push_back(v[queries[i][1]] <= queries[i][0]);
        }
        return out;
    }
};
