class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> vc(26, 200);
        for (int i = 0; i < words.size(); ++ i) {
            vector<int> vt(26, 0);
            for (int j = 0; j < words[i].size(); ++ j)
                ++ vt[words[i][j] - 'a'];
            for (int j = 0; j < 26; ++ j) {
                if (vc[j] > vt[j])
                    vc[j] = vt[j];
            }
        }
        vector<string> out;
        for (int i = 0; i < 26; ++ i) {
            for (int j = 0; j < vc[i]; ++ j) {
                out.push_back(string(1, 'a' + i));
            }
        }
        return out;
    }
};
