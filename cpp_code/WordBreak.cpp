class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word(wordDict.begin(), wordDict.end());
        int slen = s.size();
        bool out[slen + 1];
        memset(out, false, sizeof(out));
        out[0] = true;
        for (int i = 0; i < slen; ++ i) {
            for (int j = 0; j <= i; ++ j) {
                if (out[j] && word.count(s.substr(j, i - j + 1))) {
                    out[i + 1] = true;
                    break;
                }
            }
        }
        return out[slen];        
    }
};
