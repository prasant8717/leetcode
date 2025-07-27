class Solution {
private:
    int find(string& s, int l, int r, int k) {
        vector<int> vc(26);
        for (int i = l; i <= r; ++ i) {
            vc[s[i] - 'a'] ++;
        }
        char c = 0;
        for (int i = 0; i < 26; ++ i) {
            if ((vc[i] > 0) && (vc[i] < k)) {
                c = 'a' + i;
                break;
            }
        }
        if (c == 0) {
            return r - l + 1;
        }
        int cs = l;
        int m = 0;
        while (cs <= r) {
            while ((cs <= r) && (s[cs] == c)) {
                ++ cs;
            }
            if (cs > r) {
                break;
            }
            int ce = cs;
            while ((ce <= r) && (s[ce] != c)) {
                ++ ce;
            }
            int cl = find(s, cs, ce - 1, k);
            if (m < cl)
                m = cl;
            cs = ce;
        }
        return m;
    }

public:
    int longestSubstring(string s, int k) {
        return find(s, 0, s.size() - 1, k);
    }
};
