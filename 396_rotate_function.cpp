class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        int b = 0;
        for (int i = 0; i < n; ++ i) {
            a += i * nums[i];
            b += nums[i];
        }
        int res = a;
        for (int i = 1; i < n; ++ i) {
            a = a + b - n * nums[n - i];
            if (res < a)
                res = a;
        }
        return res;
    }
};
