class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        ranges::sort(folder);
        vector<string> vs;
        string s = folder[0];
        vs.push_back(s);
        for (int i = 1; i < folder.size(); ++ i) {
            size_t t = folder[i].find(s);
            if ((t == string::npos) || (t != 0) ||
                (folder[i][s.length()] != '/')) {
                vs.push_back(folder[i]);
                s = folder[i];
            }
        }
        return vs;
    }
};
