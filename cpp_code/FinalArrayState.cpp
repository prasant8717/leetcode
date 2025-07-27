class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for (int i = 0; i < k; ++ i) {
            int min = nums[0];
            int m = 0;
            for (int j = 1; j < n; ++ j) {
                if (min > nums[j]) {
                    min = nums[j];
                    m = j;
                }
            }
            nums[m] = min * multiplier;
        }
        return nums;
    }
};

