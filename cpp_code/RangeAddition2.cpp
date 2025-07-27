class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mm = m;
        int nn = n;
        for (int i = 0; i < ops.size(); ++ i) {
            if (mm > ops[i][0])
                mm = ops[i][0];
            if (nn > ops[i][1])
                nn = ops[i][1];
        }
        return (mm * nn);
    }
};
