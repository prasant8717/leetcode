class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int c = 0;
        int res = 0;
        int d = 2000;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++ i) {
            if (nums[i + 1] - nums[i] == d) {
                ++ c;
            } else {
                d = nums[i + 1] - nums[i];
                c = 0;
            }
            res += c;
        }
        return res;
    }
};
