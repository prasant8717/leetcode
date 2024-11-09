class Solution {
public:
    string getPermutation(int n, int k) {
        string out;
        vector<int> nums(n);
        vector<int> fct(n + 1, 1);
        for (int i = 0; i < nums.size(); ++ i)
            nums[i] = i + 1;
        for (int i = 2; i <= n; ++ i)
            fct[i] = fct[i - 1] * i;
        -- k;
        for (int i = n; i > 0; -- i) {
            int j = k / fct[i - 1];
            k = k % fct[i -1];
            out += to_string(nums[j]);
            nums.erase(nums.begin() + j);
        }
        return out;
    }
};
