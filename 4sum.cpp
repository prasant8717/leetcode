class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		ranges::sort(nums);
		set<vector<int>> ns;
		int n = nums.size();
		for (int i = 0; i < n - 3; i ++) {
			for (int j = i + 1; j < n - 2; j ++) {
                int l = j + 1;
                int r = n - 1;
				while (l < r) {
					long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
					if (sum == target) {
						ns.insert({nums[i], nums[j], nums[l], nums[r]});
						l ++;
						r --;
					} else if (sum < target) {
						l++;
					} else {
						r--;
					}
				}
			}
		}
		vector<vector<int>> vout(ns.begin(), ns.end());
        return vout;
    }
};
