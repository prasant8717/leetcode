class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int c = unordered_set(nums.begin(), nums.end()).size();
        vector<int> v(2001);
        int res = 0;
        int d = 0;
        int k = 0;
        for (int i = 0; i < n; ++ i) {
            if (++ v[nums[i]] == 1)
                ++ d;
            while (d == c)
                if (-- v[nums[k ++]] == 0)
                    -- d;
            res += k;
        }
        return res;
    }
};
