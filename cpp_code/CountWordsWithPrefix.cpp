class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (int i = 0; i < words.size(); ++ i) {
            int j = 0;
            for (; j < pref.size(); ++ j) {
                if (words[i][j] != pref[j])
                    break;
            }
            if (j == pref.size())
                ++ res;
        }
        return res;
    }
};
