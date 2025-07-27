class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; ++ i)
            pq.emplace(nums[i], i);
        long long res = 0;
        while (pq.empty() == 0) {
            auto [t, i] = pq.top();
            pq.pop();
            res += t;
            v[i] = true;
            if (i + 1 < n)
                v[i + 1] = true;
            if (i - 1 >= 0)
                v[i - 1] = true;
            while ((pq.empty() == 0) && (v[pq.top().second] != 0))
                pq.pop();
        }
        return res;        
    }
};
