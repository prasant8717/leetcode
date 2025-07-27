class Solution {
public:
    long long dfs(vector<long long>& vl, int p, int l,
                  string& s, string& t, int limit) {
        if (t.size() < s.size())
            return 0;
        if (!l && vl[p] != -1)
                return vl[p];
        if (t.size() - p == s.size())
            return l ? s <= t.substr(p) : 1;
        long long res = 0;
        int up = min(l ? t[p] - '0' : 9, limit);
        for (int i = 0; i <= up; ++ i)
            res += dfs(vl, p + 1, l && i == (t[p] - '0'), s, t, limit);
        if (!l)
            vl[p] = res;
        return res;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string t = to_string(start - 1);
        vector<long long> vl(20, -1);
        long long a = dfs(vl, 0, true, s, t, limit);
        t = to_string(finish);
        for (int i = 0; i < vl.size(); ++ i)
            vl[i] = -1;
        long long b = dfs(vl, 0, true, s, t, limit);
        return b - a;
    }
};
