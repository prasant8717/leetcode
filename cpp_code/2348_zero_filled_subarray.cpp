class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int idx = -1;
        long long res = 0;
        for (int i = 0; i < nums.size(); ++ i)
            if (nums[i] != 0)
                idx = i;
            else
                res += i - idx;
        return res;
    }
};
