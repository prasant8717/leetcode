class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        auto f = [&](pair<int, int>& p1, pair<int, int>& p2) {
                        return arr[p1.first] * arr[p2.second] >
                               arr[p2.first] * arr[p1.second];
                        };                
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> pq(f);
        for (int i = 1; i < n; ++ i)
            pq.push({0, i});
        for (int i = 1; i < k; ++ i) {
            pair<int, int> p = pq.top();
            pq.pop();
            if (p.first + 1 < p.second)
                pq.push({p.first + 1, p.second});
        }
        return {arr[pq.top().first], arr[pq.top().second]};
    }
};
