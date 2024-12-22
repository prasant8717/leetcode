class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool minc = true;
        for (int i = 0; i < nums.size() - 1; ++ i) {
            if (nums[i] <= nums[i + 1])
                continue;
            else {
                minc = false;
                break;
            }
        }
        if (minc == true)
            return true;
        bool mdec = true;
        for (int i = 0; i < nums.size() - 1; ++ i) {
            if (nums[i] >= nums[i + 1])
                continue;
            else {
                mdec = false;
                break;
            }
        }
        if (mdec == true)
            return true;
        return false;
    }
};
