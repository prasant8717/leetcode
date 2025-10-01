class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> out;
        for (int i = 0; i < nums.size(); ++ i) {
            while ((out.empty() == 0) &&
                   (gcd(out.back(), nums[i]) > 1))
                nums[i] = lcm(out.back(), nums[i]), out.pop_back();
            out.push_back(nums[i]);
        }
        return out;
    }
};
