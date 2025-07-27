class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sz = matrix.size();
        for (int i = 0; i < sz; ++ i) {
            int l = 0;
            int r = matrix[i].size();
            while (l < r) {
                int m = (l + r) >> 1;
                if (matrix[i][m] == target)
                    return true;
                if (matrix[i][m] > target)
                    r = m;
                else
                    l = m + 1;
            }
        }
        return false;
    }
};
