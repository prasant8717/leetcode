class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> um;
        for (int i = 0; i < s.length(); ++ i)
            um[s[i]] ++;
        vector<char> vc;
        for (auto [ch, _] : um)
            vc.push_back(ch);
        ranges::sort(vc, [&](char& c1, char& c2) {
            return um[c1] > um[c2];
        });
        string out = "";
        for (int i = 0; i < vc.size(); ++ i) {
            char ch = vc[i];
            out += string(um[ch], ch);
        }
        return out;
    }
};
