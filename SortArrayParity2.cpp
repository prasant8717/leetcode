class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int k = 1;
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] % 2) {
                while (nums[k] % 2)
                    k += 2;
                int t = nums[i];
                nums[i] = nums[k];
                nums[k] = t;;
            }
        }
        return nums;        
    }
};
