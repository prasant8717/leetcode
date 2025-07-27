class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int c[26] = { 0 };
        for (int i = 0; i < licensePlate.size(); ++ i) {
            char ch = licensePlate[i];
            if (isalpha(ch))
                c[tolower(ch) - 'a'] ++;
        }
        string out;
        for (int i = 0; i < words.size(); ++ i) {
            if ((out.size() != 0) &&
                (out.size() <= words[i].size()))
                continue;
            int w[26] = { 0 };
            for (int j = 0; j < words[i].size(); ++ j)
                w[words[i][j] - 'a'] ++;
            bool sts = true;
            for (int j = 0; j < 26; ++ j)
                if (c[j] > w[j]) {
                    sts = false;
                    break;
                }
            if (sts == true)
                out = words[i];
        }
        return out;        
    }
};
