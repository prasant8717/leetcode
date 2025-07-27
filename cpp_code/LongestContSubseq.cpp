class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        int c = 1;
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i - 1] < nums[i]) {
                ++ c;
                if (res < c)
                    res = c;
            } else {
                c = 1;
            }
        }
        return res;        
    }
};
