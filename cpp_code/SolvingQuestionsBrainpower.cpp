class Solution {
public:
    long long points(int c, int l, vector<vector<int>>& q, vector<long long>& r) {
        if (c >= l)
            return 0;
        if (r[c] > 0)
            return r[c];
        int p = q[c][0];
        int b = q[c][1];
        long long t1 = p + points(c + b + 1, l, q, r);
        long long t2 = points(c + 1, l, q, r);
        r[c] = t1;
        if (r[c] < t2)
            r[c] = t2;
        return r[c];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int r = questions.size();
        vector<long long> v(r);
        return points(0, r, questions, v);
    }
};
