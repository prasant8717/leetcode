#define T(i) nums[(1 + (i << 1)) % (n | 1)]

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto cu = nums.begin() + n / 2;
        nth_element(nums.begin(), cu, nums.end());
        int m = nums[n >> 1];
        for (int i = 0, j = 0, k = n - 1; i <= k;)
            if (T(i) > m)
                swap(T(i ++), T(j ++));
            else if (T(i) < m)
                swap(T(i), T(k --));
            else
                ++ i;
    }
};
