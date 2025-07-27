class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;
        int l = nums[0];
        for (int i = 1; i + 1 < nums.size(); ++ i)
            if ((l < nums[i]) && (nums[i] > nums[i + 1]) ||
                (l > nums[i]) && (nums[i] < nums[i + 1])) {
            ++ res;
            l = nums[i];
        }
        return res;
    }
};
