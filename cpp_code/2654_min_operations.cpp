class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        int t = ranges::count(nums, 1);
        if (t > 0)
            res = n - t;
        else {
            int op = INT_MAX;
            for (int i = 0; i < n; ++ i) {
                int k = nums[i];
                for (int j = i + 1; j < n; ++ j) {
                    if ((k = __gcd(k, nums[j])) == 1) {
                        if (op > j - i)
                            op = j - i;
                        break;
                    }
                }
            }
            if (op < INT_MAX)
                res = op + n - 1;
        }
        return res;
    }
};
