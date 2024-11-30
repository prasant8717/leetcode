class Solution {
public:
    int thirdMax(vector<int>& nums) {
        ranges::sort(nums);
        int max = INT_MIN;
        int l = nums.size();
        if (l < 3)
            max = nums[l - 1];
        else {
            int it = 0;
            for (int i = l - 1; i >= 0; -- i)
                if (it < 3)
                    if (nums[i] != max) {
                        max = nums[i];
                        ++ it;
                    }
            if (it < 3)
                max = nums[l - 1];
        }
        return max;
    }
};
