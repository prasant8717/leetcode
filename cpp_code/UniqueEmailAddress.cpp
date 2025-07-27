class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int l = emails.size();
        unordered_set<string> tvs;
        for (int i = 0; i < l; ++ i) {
            size_t p = emails[i].find('@');
            string ts = emails[i].substr(0, p);
            string dm = emails[i].substr(p + 1);
            string t;
            for (int j = 0; j < ts.size(); ++ j) {
                if (ts[j] == '.')
                    continue;
                if (ts[j] == '+')
                    break;
                t.push_back(ts[j]);
            }
            tvs.insert(t + '@' + dm);
        }
        return tvs.size();
    }
};
