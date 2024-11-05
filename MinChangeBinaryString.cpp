class Solution {
public:
    int minChanges(string s) {
        int r = s.length();
        int l = 0;
        int cnt = 0;
        while (l < r) {
            if (s[l] != s[l + 1]) {
                cnt ++;
            }
            l += 2;
            if (r - l >= 2) {
                if (s[r - 1] != s[r - 2]) {
                    cnt ++;
                }
                r -= 2;
            }
        }
        return cnt;
    }
};
