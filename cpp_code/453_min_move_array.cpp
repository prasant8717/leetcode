class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = 1 << 30;
        int s = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            s += nums[i];
            if (m > nums[i])
                m = nums[i];
        }
        return s - m * nums.size();
    }
};
