class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int mx = 0;
        int mn = 0;
        for (int i = 0; i < n; ++ i) {
            mx = max(mx, 0) + nums[i];
            mn = min(mn, 0) + nums[i];
            s = max({s, mx, abs(mn)});
        }
        return s;
    }
};
