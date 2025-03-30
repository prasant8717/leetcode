class Solution {
public:
    string reorganizeString(string s) {
        vector<int> vc(26);
        int l = s.length();
        for (int i = 0; i < l; ++ i)
            vc[s[i] - 'a'] ++;
        int f = *max_element(vc.begin(), vc.end());
        if (f > ((l + 1) >> 1))
            return "";
        vector<vector<int>> vv;
        for (int i = 0; i < 26; ++ i) {
            if (vc[i] != 0)
                vv.push_back({vc[i], i});
        }
        ranges::sort(vv, [&](auto& a, auto& b) {return a[0] > b[0];});
        string os = s;
        int j = 0;
        for (int i = 0; i < vv.size(); ++ i) {
            int t = vv[i][0];
            int u = vv[i][1];
            while (t != 0) {
                os[j] = 'a' + u;
                j += 2;
                if (j >= l)
                    j = 1;
                -- t;
            }
        }
        return os;
    }
};
