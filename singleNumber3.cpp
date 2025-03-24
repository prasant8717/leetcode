class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long s = 0;
        for (int i = 0; i < nums.size(); ++ i)
            s ^= nums[i];
        int x = 0;
        for (int i = 0; i < nums.size(); ++ i)
            if (nums[i] & (s & -s))
                x ^= nums[i];
        return {x, (int)(s ^ x)};
    }
};
