class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map;
        for (string& str : words) {
            ++ map[str];
        }
        int slen = s.size();
        int wnum = words.size();
        int wlen = words[0].size();
        vector<int> out;
        for (int i = 0; i < wlen; ++i) {
            unordered_map<string, int> fnd;
            int l = i, r = i;
            int idx = 0;
            while (r + wlen <= slen) {
                string str = s.substr(r, wlen);
                r += wlen;
                if (map.count(str) == 0) {
                    fnd.clear();
                    l = r;
                    idx = 0;
                    continue;
                }
                ++ fnd[str];
                ++ idx;
                while (fnd[str] > map[str]) {
                    string clr = s.substr(l, wlen);
                    l += wlen;
                    -- fnd[clr];
                    -- idx;
                }
                if (idx == wnum) {
                    out.push_back(l);
                }
            }
        }
        return out;
    }
};
