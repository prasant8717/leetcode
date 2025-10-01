class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        vector<string> vs;
        string s;
        while(ss >> s)
            vs.push_back(s);
        int res = 0;
        for (int i = 0; i < vs.size(); ++ i)
            for (int j = 0; j < vs[i].size(); ++ j)
                if (brokenLetters.find(vs[i][j]) != string::npos) {
                    ++ res;
                    break;
                }
        return vs.size() - res;
    }
};
