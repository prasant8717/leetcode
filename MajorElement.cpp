class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maj = nums[0];
        int max = 0;
        int res = nums[0];
        int idx = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            if (res == nums[i]) {
                ++ idx;
            } else {
                if (max < idx) {
                    max = idx;
                    maj = res;
                }
                res = nums[i];
                idx = 1;
            }
        }
        if (idx > max) {
            maj = res;
            max = idx;
        }
        if (max >= (nums.size() / 2)) {
            return maj;
        }
        return -1;
    }
};
