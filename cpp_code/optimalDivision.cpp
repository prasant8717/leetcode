class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string res = to_string(nums[0]);
        if (n == 1)
            return res;
        if (n == 2)
            return res + "/" + to_string(nums[1]);
        res += "/(";
        for (int i = 1; i < n - 1; i ++)
            res += to_string(nums[i]) + "/";
        res += to_string(nums[n - 1]) + ")";
        return res;
    }
};
