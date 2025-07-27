class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int s = 0;
        int e = 0;
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        ranges::sort(events);
        while ((pq.empty() == 0) || (e < events.size())) {
            if (pq.empty() != 0)
                s = events[e][0];
            while ((e < events.size()) && (events[e][0] == s))
                pq.push(events[e ++][1]);
            pq.pop();
            ++ res;
            ++ s;
            while ((pq.empty() == 0) && (pq.top() < s))
                pq.pop();
        }
        return res;
    }
};
