class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> vp(26);
        for (int i = 0; i < order.size(); ++ i)
            vp[order[i] - 'a'] = i;
        ranges::sort(s, [&](auto& a, auto& b) { return vp[a - 'a'] < vp[b - 'a'];});
        return s;
    }
};
