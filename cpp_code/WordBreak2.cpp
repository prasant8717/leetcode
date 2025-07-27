class Solution {
public:
    vector<string> wbreak(string& s, unordered_set<string>& wus,
                    unordered_map<string, vector<string>>& ums) {
        if (auto m = ums.find(s); m != ums.cend())
            return m->second;
        vector<string> vs;
        for (int i = 1; i < s.length(); ++ i) {
            string px = s.substr(0, i);
            string sx = s.substr(i);
            if (wus.contains(px) != 0) {
                vector<string> ws = wbreak(sx, wus, ums);
                for (int i = 0; i < ws.size(); ++ i)
                    vs.push_back(px + " " + ws[i]);
            }
        }
        if (wus.contains(s))
            vs.push_back(s);
        return ums[s] = vs;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wus{wordDict.begin(), wordDict.end()};
        unordered_map<string, vector<string>> ums;
        return wbreak(s, wus, ums);
    }
};
