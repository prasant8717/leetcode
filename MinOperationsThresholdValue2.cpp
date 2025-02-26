class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < nums.size(); ++ i) {
            pq.push(nums[i]);
        }
        int res = 0;
        for (; pq.size() > 1 && pq.top() < k; ++ res) {
            long long l = pq.top();
            pq.pop();
            long long t = pq.top();
            pq.pop();
            pq.push((l << 1) + t);
        }
        return res;
    }
};
