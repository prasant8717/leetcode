class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> out;
        int ls = s.size();
        int i = 0;
        while (i < ls) {
            int j = i;
            while ((j < ls) && (s[j] == s[i]))
                ++ j;
            if ((j - i) >= 3)
                out.push_back({i, j - 1});
            i = j;
        }
        return out;        
    }
};
