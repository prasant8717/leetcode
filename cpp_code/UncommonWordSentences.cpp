class Solution {
public:
    void add_hash(string& s, unordered_map<string, int>& mp) {
        stringstream ss(s);
        string w;
        while (ss >> w)
            ++ mp[w];
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> um;
        add_hash(s1, um);
        add_hash(s2, um);
        vector<string> out;
        for (auto [s, t] : um)
            if (t == 1)
                out.push_back(s);
        return out;
    }
};
