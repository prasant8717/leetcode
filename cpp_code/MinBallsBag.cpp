class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int r = 0;
        for (int i = 0; i < n; ++ i) {
            if (r < nums[i])
                r = nums[i];
        }
        int l = 1;
        while (l < r) {
            int m = (l + r) >> 1;
            long long ll = 0;
            for (int i = 0; i < n; ++ i)
                ll += (nums[i] - 1) / m;
            if (ll <= maxOperations)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
