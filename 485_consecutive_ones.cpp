class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int m = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == 1) {
                ++ m;
                if (res < m)
                    res = m;
            } else {
                m = 0;                    
            }
        }
        return res;
    }
};
