class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> d(n + 1);
        for (int i = 0; i < shifts.size(); ++ i) {
            if (shifts[i][2] == 0)
                -- shifts[i][2];
            d[shifts[i][0]] += shifts[i][2];
            d[shifts[i][1] + 1] -= shifts[i][2];
        }
        for (int i = 1; i <= n; ++ i)
            d[i] += d[i - 1];
        string res;
        for (int i = 0; i < n; ++ i) {
            int j = ((s[i] - 'a') + (d[i] % 26) + 26) % 26;
            res += ('a' + j);
        }
        return res;
    }
};
