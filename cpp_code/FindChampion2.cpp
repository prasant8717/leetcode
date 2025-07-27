class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> out(n);
        int res = -1;
        int c = 0;
        for (int i = 0; i < edges.size(); ++ i)
            out[edges[i][1]] ++;
        for (int i = 0; i < n; ++ i)
            if (out[i] == 0) {
                c ++;
            res = i;
        }
        if (c > 1)
            res = -1;
        return res;        
    }
};
