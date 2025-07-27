class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> p;
        for (int i = 2; i <= 1000; ++ i) {
            bool ret = true;
            for (int j = 0; j < p.size(); ++ j) {
                if (i % p[j] == 0) {
                    ret = false;
                    break;
                }
            }
            if (ret == true) {
                p.push_back(i);
            }
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            int j = upper_bound(p.begin(), p.end(), nums[i] - nums[i + 1]) - p.begin();
            if ((j == p.size()) || (p[j] >= nums[i])) {
                return false;
            }
            nums[i] -= p[j];
        }
        return true;        
    }
};
