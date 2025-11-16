class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int res = 0;
        int t = 0;
        for (int i = 0; i + t <= n;) {
            int k = -1;
            int ac[2] = {0, 0};
            int l = 0;
            int r = 0;
            for (; r < n; ++ r) {
                ++ ac[s[r] - '0'];
                for (; l < r; ++ l)
                    if ((s[l] == '0') && (ac[0] > i)) {
                        -- ac[0];
                        k = l;
                    } else if ((s[l] == '1') && (ac[1] - 1 >= t))
                        -- ac[1];
                    else
                        break;
                if ((ac[0] == i) && (ac[1] >= t))
                    res += l - k;
            }
            ++ i;
            t = i * i;
        }
        return res;
    }
};
