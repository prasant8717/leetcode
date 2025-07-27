class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int l = chars.length();
        vector<int> vc(26);
        for (int i = 0; i < l; ++ i)
            vc[chars[i] - 'a'] ++;
        int res = 0;
        for (int i = 0; i < words.size(); ++ i) {
            vector<int> vt(vc);
            for (int j = 0; j < words[i].size(); ++ j)
                if (-- vt[words[i][j] - 'a'] < 0) {
                    res -= words[i].length();
                    break;
                }
                res += words[i].length();
        }
        return res;
    }
};
