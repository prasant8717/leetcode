class Solution {
public:
    int maxFreqSum(string s) {
        int cnt[26];
        int mv = 0;
        int mc = 0;
        string sv = "aeiou";
        for (int i = 0; i < s.length(); ++ i) {
            char c = s[i] - 'a';
            cnt[c] ++;
            if (sv.find(s[i]) != string::npos) {
                if (mv < cnt[c])
                    mv = cnt[c];
            } else {
                if (mc < cnt[c])
                    mc = cnt[c];
            }
        }
        return mv + mc;
    }
};
