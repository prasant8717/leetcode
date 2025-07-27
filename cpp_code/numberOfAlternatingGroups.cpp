class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int c = 0;
        int res = 0;
        for (int i = 0; i < (n << 1); ++ i) {
            if ((i != 0) && (colors[i % n] == colors[(i - 1) % n]))
                c = 1;
            else
                ++ c;
            if ((i >= n) && (c >= k))
                res += 1;
        }
        return res;
    }
};
