class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ranges::sort(g);
        ranges::sort(s);
        int res = 0;
        int lg = g.size();
        int ls = s.size();
        for (int i = 0; i < lg; ++ i) {
            while ((res < ls) && (s[res] < g[i]))
                ++ res;
            if (res ++ >= ls)
                return i;
        }
        return lg;
    }
};
