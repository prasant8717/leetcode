class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;
        for (int i = 0; i < n - 1; ++ i) {
            int p1 = (nums[i] % 2);
            int p2 = (nums[i + 1] % 2);
            if (p1 == p2)
                return false;
        }
        return true;
    }
};
