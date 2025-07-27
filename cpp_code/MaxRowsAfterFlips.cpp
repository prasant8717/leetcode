class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int res = 0;
        unordered_map<string, int> map;
        for (int i = 0; i < matrix.size(); ++ i) {
            string s;
            for (int j = 0; j < matrix[0].size(); ++ j) {
                s.push_back('0' + (matrix[i][0] == 0 ? matrix[i][j] : matrix[i][j] ^ 1));
            }
            if (res < ++ map[s])
                res = map[s];
        }
        return res;
    }
};
