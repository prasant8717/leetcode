class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <vector<int>, vector<vector<int>>, function <bool(vector<int>, vector<int>)> > 
            max_heap([](vector<int> x, vector<int> y) {
            return x[0]*x[0] + x[1]*x[1] < y[0]*y[0] + y[1]*y[1];
        });
        max_heap.emplace(points[0]);
        for (int i = 1; i < points.size(); i++) {
            if (max_heap.size() < k) {
                max_heap.emplace(points[i]);
            } else {
                double d1 = points[i][0] * points[i][0] + points[i][1] * points[i][1];
                vector<int> v = max_heap.top();
                double d2 = v[0] * v[0] + v[1] * v[1]; 
                if (d1 < d2) {
                    max_heap.pop();
                    max_heap.emplace(points[i]);
                }
            }
        }
        vector<vector<int>> result = {};
        while (!empty(max_heap)) {
            result.push_back(max_heap.top());
            max_heap.pop();
        }
        return {rbegin(result), rend(result)};
    }
};
