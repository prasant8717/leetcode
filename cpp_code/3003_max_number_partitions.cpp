class Solution {
private:
    int check(unordered_map<long, int>& um, string& s, int i,
             bool f, unsigned m, int n, int k) {
        unsigned int nm = m | n;
        if (popcount(nm) > k)
            return 1 + count_op(s, um, i + 1, f, n, k);
        return count_op(s, um, i + 1, f, nm, k);
    }

    int count_op(string& s, unordered_map<long, int>& um,
                 int i, bool f, int m, int k) {
        int res = 0;
        if (i != s.length()) {
            long long l = (static_cast<long long>(i) << 27) |
                         (f ? 1 : 0) << 26 | m;
            if (auto t = um.find(l); t != um.end())
                res = t->second;
            else {
                res = check(um, s, i, f, m, 1 << (s[i] - 'a'), k);
                if (f)
                    for (int j = 0; j < 26; ++ j) {
                        int r = check(um, s, i, false, m, 1 << j, k);
                        if (res < r)
                            res = r;
                    }
            }
            um[l] = res;
        }
        return res;
    }

public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long, int> um;
        return count_op(s, um, 0, true, 0, k) + 1;
    }
};
