class Solution {
public:
    int dayOfYear(string date) {
        int y = (date[3] - '0') + (10 * (date[2] - '0')) +
                (100 * (date[1] - '0')) + (1000 * (date[0] - '0'));
        int m = (date[6] - '0') + (10 * (date[5] - '0'));
        int d = (date[9] - '0') + (10 * (date[8] - '0'));
        int lp = 0;
        if ((y % 100 == 0) && (y % 400 == 0))
            lp = 1;
        else if ((y % 100 != 0) && (y % 4 == 0))
            lp = 1;
        int md[13] = { 0, 31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31 };
        int res = d;
        if (m > 2)
            res += lp;
        for (int i = 0; i < m; ++ i)
            res += md[i];
        return res;
    }
};
