class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> pq;
        int n = classes.size();
        for (int i = 0; i < n; ++ i) {
            int p = classes[i][0];
            int t = classes[i][1];
            double dl = ((double) (p + 1) / (t + 1)) -
                         ((double) p / t);
            pq.push({dl, p, t});
        }
        for (int i = 1; i <= extraStudents; ++ i) {
            auto [dl, p, t] = pq.top();
            pq.pop();
            p ++;
            t ++;
            double dt = ((double) (p + 1) / (t + 1)) -
                         ((double) p / t);
            pq.push({dt, p, t});
        }
        double res = 0.0;
        for (int i = pq.size(); i > 0; -- i) {
            auto [dl, p, t] = pq.top();
            pq.pop();
            res += ((double) p / t);
        }
        return res / n;
    }
};
