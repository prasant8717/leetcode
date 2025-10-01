class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        char cnt[101];
        int m = 0;
        cnt[0] = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            ++ cnt[nums[i]];
            int t = cnt[nums[i]];
            if (m < t)
                m = t;
        }
        int res = 0;
        for (int i = 1; i < 101; ++ i)
            if (cnt[i] == m)
                res += cnt[i];
        return res;
    }
};
