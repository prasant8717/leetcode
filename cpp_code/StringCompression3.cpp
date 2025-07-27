class Solution {
public:
    string compressedString(string word) {
        string out;
        int l = word.length();
        string ai = "0123456789";
        for (int i = 0; i < l;) {
            int j = i + 1;
            while ((j < l) && (word[j] == word[i])) {
                ++ j;
            }
            int k = j - i;
            while (k > 0) {
                int n = k;
                if (k > 9)
                    n = 9;
                out.push_back(ai[n]);
                out.push_back(word[i]);
                k -= n;
            }
            i = j;
        }
        return out;
    }
};
