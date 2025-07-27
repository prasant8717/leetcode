class Solution {
public:
    bool check(vector<int>& n, int m, int k) {
        int c = 0;
        int t = -1;
        for (int i = 0; i < n.size(); ++ i) {
            if ((n[i] > m) || (i == t))
                continue;
            ++ c;
            t = i + 1;
        }
        return c >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = 0;
        int r = nums[0];
        for (int i = 1; i < nums.size(); ++ i) {
            if (r < nums[i])
                r = nums[i];
        }
        while (l < r) {
            int m = (l + r) >> 1;
            if (check(nums, m, k) == true)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
