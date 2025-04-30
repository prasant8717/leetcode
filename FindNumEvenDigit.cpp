class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            int t = nums[i];
            int k = 0;
            while (t) {
                ++ k;
                t /= 10;
            }
            if ((k % 2) == 0)
                ++ n;
        }
        return n;
    }
};
