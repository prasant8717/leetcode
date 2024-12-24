class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string out;
        unordered_map<string, int> cnt;
        unordered_set<string> us(banned.begin(), banned.end());
        int m = 0;
        int n = paragraph.size();
        for (int i = 0; i < n;) {
            if ((isalpha(paragraph[i]) == 0) &&
                (++ i > 0))
                continue;
            int j = i;
            string w;
            while ((j < n) && (isalpha(paragraph[j]) != 0) ) {
                w.push_back(tolower(paragraph[j]));
                ++ j;
            }
            i = j + 1;
            if (us.count(w) != 0)
                continue;
            ++ cnt[w];
            if (cnt[w] > m) {
                out = w;
                m = cnt[w];
            }
        }
        return out;        
    }
};
