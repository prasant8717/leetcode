class Solution {
public:
    bool toPunish(string& s, int i, int n) {
        int sz = s.size();
        if (i >= sz) {
            return n == 0;
        }
        int t = 0;
        for (int k = i; k < sz; ++ k) {
            t = t * 10 + s[k] - '0';
            if (t > n) {
                break;
            }
            if (toPunish(s, k + 1, n - t)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++ i) {
            int t = i * i;
            string s = to_string(t);
            if (toPunish(s, 0, i) == true) {
                res += t;
            }
        }
        return res;
    }
};
