class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int k = 0;
        for (int i = 1; i <= n; ++ i) {
            int r = (i % 7);
            if (r)
                res += r + k;
            else {
                res += 7 + k;
                ++ k;
            }
        }
        return res;
    }
};
