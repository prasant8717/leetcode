class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> v(n);
        for (int i = 0; i < n; ++ i)
            v[i] = ((nums[i] % modulo) == k);
        unordered_map<int, int> uc;
        uc[0] = 1;
        long long res = 0;
        int s = 0;
        for (int i = 0; i < n; ++ i) {
            s += v[i];
            res += uc[((s - k) + modulo) % modulo];
            uc[s % modulo] ++;
        }
        return res;
    }
};
