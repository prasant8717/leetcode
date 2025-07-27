class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int, vector<int>> pq;
        int n = gifts.size();
        for (int i = 0; i < n; ++ i)
            pq.push(gifts[i]);
        for (int i = 0; i < k; ++ i) {
            int t = pq.top();
            pq.pop();
            t = sqrt(t);
            pq.push(t);
        }
        long long sum = 0;
        for (int i = 0; pq.size(); ++ i) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
