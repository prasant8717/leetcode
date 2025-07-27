class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        ranges::sort(nums);
        vector<vector<int>> out;
        for (int i = 0; i < n - 2; i += 3) {
            if ((nums[i + 2] - nums[i]) > k)
                return {};
            vector<int> v = {nums[i], nums[i + 1], nums[i + 2]};
            out.push_back(v);            
        }
        return out;
    }
};
