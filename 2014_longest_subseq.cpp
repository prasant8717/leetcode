class Solution {
private:
    bool subseq(string& ss, string& s, int k) {
        int i = 0;
        for (char c : s)
            if (c == ss[i])
                if (++ i == ss.length()) {
                    if (-- k == 0)
                        return true;
                    i = 0;
                }
        return false;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string out;
        vector<int> vn(26);
        vector<char> vc;
        queue<string> qs{{""}};
        for (char c : s)
            ++ vn[c - 'a'];
        for (char c = 'a'; c <= 'z'; ++ c)
            if (vn[c - 'a'] >= k)
                vc.push_back(c);
        while (qs.empty() == 0) {
            string cs = qs.front();
            qs.pop();
            if (cs.length() * k > s.length())
                return out;
            for (char c : vc) {
                string ns = cs + c;
                if (subseq(ns, s, k)) {
                    qs.push(ns);
                    out = ns;
                }
            }
        }
        return out;
    }
};
