class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> um1;
        unordered_map<int, int> um2;
        vector<int> out;
        for (int i = 0; i < queries.size(); ++ i) {
            int t1 = queries[i][0];
            int t2 = queries[i][1];
            um2[t2]++;
            if (um1.contains(t1) != 0) {
                -- um2[um1[t1]];
                if (um2[um1[t1]] == 0) {
                    um2.erase(um1[t1]);
                }
            }
            um1[t1] = t2;
            out.push_back(um2.size());
        }
        return out;
    }
};
