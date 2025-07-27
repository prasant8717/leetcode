class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int num = points.size();
        int res = 1;
        for (int i = 0; i < num; ++ i) {
            int px1 = points[i][0];
            int py1 = points[i][1];
            for (int j = i + 1; j < num; ++ j) {
                int px2 = points[j][0];
                int py2 = points[j][1];
                int tmp = 2;
                for (int k = j + 1; k < num; ++ k) {
                    int px3 = points[k][0];
                    int py3 = points[k][1];
                    int a = (py2 - py1) * (px3 - px1);
                    int b = (py3 - py1) * (px2 - px1);
                    tmp += a == b;
                }
                if (res < tmp) {
                    res = tmp;
                }
            }
        }
        return res;        
    }
};
