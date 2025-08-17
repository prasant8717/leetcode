class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int m = 1e9 + 7;
        int b = 30;
        vector<int> out;
        vector<int> pow;
        for (int i = 0; i < b; ++ i)
            if ((n >> i) & 1)
                pow.push_back(1 << i);
        for (int i = 0; i < queries.size(); ++ i) {
            int l = queries[i][0];
            int r = queries[i][1];
            long long t = 1;
            for (int i = l; i <= r; ++ i) {
                t *= pow[i];
                t %= m;
            }
            out.push_back(t);
        }
        return out;
    }
};
