class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int b = 131;
        int k = 0;
        unsigned long long px = 0;
        unsigned long long sx = 0;
        unsigned long long ml = 1;
        for (int i = 0; i < n; ++ i) {
            int t = (s[i] - 'a') + 1;
            px = (px * b) + t;
            sx = sx + (ml * t);
            ml *= b;
            if (px == sx)
                k = i + 1;
        }
        if (k == n)
            return s;
        string ts = s.substr(k, n - k);
        reverse(ts.begin(), ts.end());
        return ts + s;
    }
};
