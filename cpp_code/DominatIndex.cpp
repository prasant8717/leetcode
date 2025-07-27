class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int max = 0;
        int m = 0;
        for (int i = 0; i < n; ++ i) {
            if (max < nums[i]) {
                max = nums[i];
                m = i;
            }
        }
        for (int i = 0; i < n; ++ i) {
            if (i != m) {
                if (max < (nums[i] << 1))
                    return -1;
            }
        }
        return m;
    }
};
