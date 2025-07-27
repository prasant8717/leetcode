class Solution {
private:
    int calc(string& s, char a, char b, int k) {
        int res = 0;
        int mx = 0;
        int cnt = 0;
        for (int i = 0; i < s.length(); ++ i) {
            if (s[i] == a || s[i] == b) {
                ++ mx;
            } else if (cnt < k) {
                ++ mx;
                ++ cnt;
            } else {
                -- mx;
            }
            if (res < mx)
                res = mx;
        }
        return res;
    }
public:
    int maxDistance(string s, int k) {
        int a = calc(s, 'S', 'E', k);
        int b = calc(s, 'S', 'W', k);
        int c = calc(s, 'N', 'E', k);
        int d = calc(s, 'N', 'W', k);
        return max({a, b, c, d});
    }
};
