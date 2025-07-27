class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> v;
        for (int i = 1; i < n; ++ i)
            v.push_back(i);
        vector<int> out;
        int c = n - 1;
        for (int i = 0; i < queries.size(); ++ i) {
            int q1 = queries[i][0];
            int q2 = queries[i][1];
            if ((v[q1] > 0) && (v[q1] < q2)) {
                int tt = v[q1];
                while (tt < q2) {
                    c --;
                    int t = v[tt];
                    v[tt] = 0;
                    tt = t;
                }
                v[q1] = q2;
            }
            out.push_back(c);
        }
        return out;        
    }
};
