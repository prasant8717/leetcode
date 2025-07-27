class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vp(26);
        int n = s.size();
        for (int i = 0; i < n; ++ i) {
            vp[s[i] - 'a'] = i;
        }
        string out;
        int m = 0;
        for (int i = 0; i < n; ++ i) {
            char c = s[i];
            if ((m >> (c - 'a')) & 1) {
                continue;
            }
            while (!out.empty() && out.back() > c &&
                vp[out.back() - 'a'] > i) {
                m ^= 1 << (out.back() - 'a');
                out.pop_back();
            }
            out.push_back(c);
            m |= 1 << (c - 'a');
        }
        return out;
    }
};
