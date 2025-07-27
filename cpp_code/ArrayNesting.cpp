class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n);
        int res = 0;
        for (int i = 0; i < n; ++ i) {
            if (v[i] != 0)
                continue;
            int c = nums[i];
            int m = 1;
            v[c] = true;
            while (nums[c] != nums[i]) {
                c = nums[c];
                ++ m;
                v[c] = true;
            }
            if (res < m)
                res = m;
        }
        return res;
    }
};
