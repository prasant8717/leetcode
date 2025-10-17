class Solution {
private:
    bool check(string& s1, string& s2) {
        bool sts = false;
        int l = s1.size();
        if (l == s2.size()) {
            vector<int> vc(26);
            for (int i = 0; i < l; ++ i) {
                ++ vc[s1[i] - 'a'];
                -- vc[s2[i] - 'a'];
            }
            sts = ranges::all_of(vc, [](const int c) { return c == 0; });
        }
        return sts;
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> out;
        for (int i = 0; i < words.size();) {
            int j = i + 1;
            while ((j < words.size()) && (check(words[i], words[j])))
                ++ j;
            out.push_back(words[i]);
            i = j;
        }
        return out;
    }
};
