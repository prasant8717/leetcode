class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int op = 0;
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int tmp = nums[l] + nums[r];
            if (tmp < k)
            {
                l ++;
            }
            else if (tmp > k)
            {
                r --;
            }
            else
            {
                l ++;
                op ++;
                r --;
            }
        }
        return op;
    }
};
