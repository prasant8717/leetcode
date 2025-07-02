class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        int res = 10;
        for (int j = 2; j <= n; ++ j) {
            int fk = 9;
            for (int i = j; i > 1; -- i) {
                fk *= (9 - i + 2);
            }
            res += fk;
        }
        return res;
    }
};
