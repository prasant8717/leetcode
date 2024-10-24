class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        long long max = 0;
        long long sum = 0;
        vector<pair<int, int>> nums(nums1.size());
        for (int i = 0; i < nums1.size(); ++i)
            nums[i] = {-nums2[i], nums1[i]};
        sort(nums.begin(), nums.end());
        for (auto& [n2, n1] : nums) {
            pq.push(n1);
            sum += n1;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                if (max < sum * -n2) {
                    max = sum * -n2;
                }
            }
        }
        return max;
    }
};
