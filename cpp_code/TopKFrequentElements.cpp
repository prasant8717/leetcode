class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++ i) {
            map[nums[i]] ++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& [t, c] : map) {
            pq.push({c, t});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> vout;
        while (pq.empty() == 0) {
            vout.push_back(pq.top().second);
            pq.pop();
        }
        return vout;        
    }
};
