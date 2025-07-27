class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> cs;
        string kr = "12210111011122000010020202";
        for (int i = 0; i < words.size(); ++ i) {
            int r = kr[tolower(words[i][0]) - 'a'];
            bool f = true;
            for (int j = 0; j < words[i].size(); ++ j) {
                if (r != kr[tolower(words[i][j]) - 'a']) {
                    f = false;
                    break;
                }
            }
            if (f == true)
                cs.push_back(words[i]);
        }
        return cs;
    }
};
