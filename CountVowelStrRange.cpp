class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
#if 0
        int lq = queries.size();
        vector<int> out(lq);
        for (int i = 0; i < lq; ++ i) {
            int c = 0;
            for (int j = queries[i][0]; j <= queries[i][1]; ++ j) {
                char chs = words[j][0];
                char che = words[j][words[j].size() - 1];
                string vs = "aeiou";
                if ((vs.find(chs) != string::npos) &&
                    (vs.find(che) != string::npos))
                    ++ c;
            }
            out[i] = c;
        }
        return out;
#else
        vector<int> vc;
        unordered_set<char> usv = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < words.size(); ++ i) {
            char chs = words[i][0];
            char che = words[i][words[i].size() - 1];
            if ((usv.count(chs) != 0) &&
                (usv.count(che) != 0))
                vc.push_back(i);
        }
        vector<int> out;
        for (int i = 0; i < queries.size(); ++ i) {
            int l = queries[i][0];
            int r = queries[i][1];
            int c = upper_bound(vc.begin(), vc.end(), r) - 
                      lower_bound(vc.begin(), vc.end(), l);
            out.push_back(c);
        }
        return out;
#endif
    }
};
