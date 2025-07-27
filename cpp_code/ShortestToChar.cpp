class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int l = s.length();
        vector<int> out(l, l + 1);
        int p = -1e5;
        for (int i = 0; i < l; ++ i) {
            if (s[i] == c)
                p = i;
            if (out[i] > (i - p))
                out[i] = i - p;
        }
        int k = 1e5;
        for (int i = l - 1; i >= 0; -- i) {
            if (s[i] == c)
                k = i;
            if (out[i] > (k - i))
                out[i] = k - i;
        }
        return out;
    }
};
