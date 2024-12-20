class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n = 1;
        int l = 0;
        for (int i = 0; i < s.size(); ++ i) {
            int w = widths[s[i] - 'a'];
            if (l + w <= 100)
                l += w;
            else {
                ++ n;
                l = w;
            }
        }
        return {n, l};
    }
};
