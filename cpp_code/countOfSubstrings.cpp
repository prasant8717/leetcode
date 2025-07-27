class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a') || (c == 'e') ||
               (c == 'i') || (c == 'o') || (c == 'u');
    }
    long long func(string& s, int k) {
        unordered_map<char, int> um;
        int l = 0;
        int r = 0;
        long long res = 0;
        for (int i = 0; i < s.length(); ++ i) {
            if (isVowel(s[i]) == true)
                um[s[i]] ++;
            else
                ++ r;
            while ((r >= k) && (um.size() == 5)) {
                char c = s[l ++];
                if (isVowel(c) == true) {
                    if (-- um[c] == 0)
                        um.erase(c);
                } else {
                    -- r;
                }
            }
            res += l;
        }
        return res;
    }
    long long countOfSubstrings(string word, int k) {
        return func(word, k) - func(word, k + 1);
    }
};
