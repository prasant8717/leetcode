class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> out;
        for (int i = 0; i < n; ++ i)
            out.push_back(nums[i] * nums[i]);
        ranges::sort(out);
        return out;
    }
};
