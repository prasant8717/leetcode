class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> c1(n + 1);
        vector<int> c2(n + 1);
        for (int i = 0; i < trust.size(); ++ i) {
            int t1 = trust[i][0];
            int t2 = trust[i][1];
            ++ c1[t1];
            ++ c2[t2];
        }
        for (int i = 1; i <= n; ++ i)
            if ((c1[i] == 0) && (c2[i] == n - 1))
                return i;
        return -1;
    }
};
