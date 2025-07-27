class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vc(n * n + 1);
        vector<int> out(2);
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j)
                if (++ vc[grid[i][j]] == 2)
                    out[0] = grid[i][j];
        for (int i = 1; ; ++ i)
            if (vc[i] == 0) {
                out[1] = i;
                break;
            }
        return out;
    }
};
