class Solution {
private:
    vector<vector<double>> vv =
        vector<vector<double>>(4800 / 25, vector<double>(4800 / 25));

    double calc(int i, int j) {
        if ((i <= 0) && (j <= 0))
            return 0.5;
        else if (i <= 0)
            return 1.0;
        else if (j <= 0)
            return 0.0;
        else if (vv[i][j] > 0)
            return vv[i][j];
        return vv[i][j] = 0.25 * (calc(i - 4, j) + calc(i - 3, j - 1) +
                        calc(i - 2, j - 2) + calc(i - 1, j - 3));
    }

public:
    double soupServings(int n) {
        if (n >= 4800)
            return 1.0;
        else {
            int t = (n + 24) / 25;
            return calc(t, t);
        }
    }
};
