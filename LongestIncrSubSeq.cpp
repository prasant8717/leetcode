class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vout;
        for (int num : nums) {
            if ((vout.empty() != 0) || (num > vout.back())) {
                vout.push_back(num);
            }
            else {
                int tmp;
                tmp = ranges::lower_bound(vout, num) - vout.begin();
                vout[tmp] = num;
            }
        }
        return vout.size();        
    }
};
