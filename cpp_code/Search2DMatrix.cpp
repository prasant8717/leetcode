class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int r = matrix.size();
        int c = matrix[0].size();
        int st = 0;
        int en = r * c;
        while (st < en) {
            int m = (st + en) / 2;
            if (matrix[m / c][m % c] == target)
                return true;
            if (matrix[m / c][m % c] < target)
                st = m + 1;
            else
                en = m;
        }
        return false;
    }
};
