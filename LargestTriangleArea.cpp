class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0.0;
        int n = points.size();
        for (int i = 0; i < n - 2; ++ i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n - 1; ++ j) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                for (int k = j + 1; k < n; ++ k) {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    int l1 = x2 - x1;
                    int b1 = y2 - y1;
                    int l2 = x3 - x1;
                    int b2 = y3 - y1;
                    double t = ((l1 * b2) - (l2 * b1)) / 2.0;
                    if (t < 0)
                        t = 0.0 - t;
                    if (area < t)
                        area = t;
                }
            }
        }
        return area;        
    }
};
