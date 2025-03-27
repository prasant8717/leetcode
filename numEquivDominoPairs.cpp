class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        vector<int> vc(100);
        for (int i = 0; i < dominoes.size(); ++ i) {
            int t1 = dominoes[i][0];
            int t2 = dominoes[i][1];
            int t = (10 * t1) + t2;
            if (t1 > t2)
                t = (t2 * 10) + t1;
            res += vc[t] ++;
        }
        return res;
    }
};
