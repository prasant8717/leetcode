class Solution {
public:
    int takeCharacters(string s, int k) {
        int l = s.length();
        int c[3] = {0, 0, 0};
        for (int i = 0; i < l; ++ i)
            ++ c[s[i] - 'a'];
        for (int i = 0; i < 3; ++ i)
            if (c[i] < k)
                return -1;
        int max = 0;
        int p = 0;
        for (int i = 0; i < l; ++ i) {
            int t = s[i] - 'a';
            -- c[t];
            while (c[t] < k)
                ++ c[s[p ++] - 'a'];
            if (max < (i - p + 1))
                max = i - p + 1;
        }
        return l - max;
    }
};
