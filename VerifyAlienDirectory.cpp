class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> map(26);
        for (int i = 0; i < 26; ++i)
            map[order[i] - 'a'] = i + 'a';
        for (int i = 0; i < words.size(); ++ i)
            for (int j = 0; j < words[i].size(); ++ j)
                words[i][j] = map[words[i][j] - 'a'];
        bool sts = is_sorted(words.begin(), words.end());
        return sts;
    }
};
