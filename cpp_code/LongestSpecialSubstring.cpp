class Solution {
public:
    bool test(string s, int m, int n) {
        int c[26] = {0};
        for (int i = 0; i < n;) {
            int j = i + 1;
            while ((j < n) && (s[i] == s[j]))
                ++ j;
            int k = s[i] - 'a';
            int t = j - i - m + 1;
            if (t > 0)
                c[k] += t;
            if (c[k] >= 3)
                return true;
            i = j;
        }
        return false;
    }
    int maximumLength(string s) {
        int n = s.size();
        int l = 0;
        int r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (test(s, mid, n)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (l == 0)
            return -1;
        return l;        
    }
};
