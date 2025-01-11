class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int c1[26];
        int c2[26] = {0};
        for (int i = 0; i < words2.size(); ++ i) {
            memset(c1, 0, sizeof(c1));
            for (int j = 0; j < words2[i].size(); ++ j)
                c1[words2[i][j] - 'a'] ++;
            for (int k = 0; k < 26; ++ k)
                if (c2[k] < c1[k])
                    c2[k] = c1[k];
        }
        vector<string> out;
        for (int i = 0; i < words1.size(); ++ i) {
            memset(c1, 0, sizeof(c1));
            for (int j = 0; j < words1[i].size(); ++ j)
                c1[words1[i][j] - 'a'] ++;
            bool sts = true;
            for (int k = 0; k < 26; ++ k) {
                if (c2[k] > c1[k]) {
                    sts = false;
                    break;
                }
            }
            if (sts == true)
                out.push_back(words1[i]);
        }
        return out;        
    }
};
