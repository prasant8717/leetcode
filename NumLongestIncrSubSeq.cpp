class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int l = nums.size();
        int res = 0;
        vector<int> len(l, 1);
        vector<int> ss(l, 1);
        int max = 0;
        for (int i = 0; i < l; ++ i) {
            for (int j = 0; j < i; ++ j) {
                if (nums[j] < nums[i]) {
                    if (ss[i] < ss[j] + 1) {
                        ss[i] = ss[j] + 1;
                        len[i] = len[j];
                    } else if (ss[i] == ss[j] + 1) {
                        len[i] += len[j];
                    }
                }
            }
            if (max < ss[i]) {
                max = ss[i];
                res = len[i];
            } else if (max == ss[i]) {
                res += len[i];
            }
        }
        return res;        
    }
};
