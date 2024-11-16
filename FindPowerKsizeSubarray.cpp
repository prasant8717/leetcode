class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int l = nums.size();
        vector<int> v(k);
        vector<int> o(l - k + 1);
        int idx = 0;
        for (int i = 0; i < l - k + 1; i ++) {
            int j = 0;
            for (; j < k; ++ j) {
                if ((j != 0) && (v[j - 1] != nums[i + j] - 1)) {
                    break;
                }
                v[j] = nums[j + i];
            }
            if (j != k)
                o[idx] = -1;
            else
                o[idx] = v[k - 1];
            ++ idx;
        }
        return o;
    }
};
