class Solution {
public:
    int numSub(string s) {
        int res = 0;
        int k = 0;
        int m = 1e9 + 7;
        for (int i = 0; i < s.length(); ++ i) {
            if (s[i] == '1')
                ++ k;
            else {
                int t = ((((long long)k + 1) * k) >> 1) % m;
                res += t;
                k = 0;
            }
        }
        int t = (((k + 1) * k) >> 1) % m;
        res += t;
        return res;
    }
};
