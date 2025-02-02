class Solution {
public:
    bool check(vector<int>& nums) {
        int l = nums.size();
        int r = 0;
        for (int i = 0; i < l - 1; ++ i) {
            r += (nums[i] > nums[i + 1]);
        }
        r += (nums[l - 1] > nums[0]);
        return r <= 1;
    }
};
