class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        ranges::sort(nums);
        int k = 0;
        for (int i = 0; i < n; ++ i) {
            v[i] = 1;
            for (int j = 0; j < i; ++ j)
                if ((nums[i] % nums[j]) == 0)
                    if (v[i] < v[j] + 1)
                        v[i] = v[j] + 1;
            if (v[k] < v[i])
                k = i;
        }
        int t = v[k];
        vector<int> res;
        for (int i = k; t > 0; -- i)
            if (((nums[k] % nums[i]) == 0) && (v[i] == t)) {
                res.push_back(nums[i]);
                k = i;
                -- t;
            }
        return res;
    }
};
