class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        int l = s.length();
        vector<int> vf(26, l);
        vector<int> vl(26);
        for (int i = 0; i < l; ++ i) {
            int t = s[i] - 'a';
            if (vf[t] > i)
                vf[t] = i;
            vl[t] = i;
        }
        for (int i = 0; i < 26; ++ i)
            if (vf[i] < vl[i])
                res += unordered_set<int>(s.begin() + vf[i] + 1,
                                      s.begin() + vl[i]).size();
        return res;
    }
};
