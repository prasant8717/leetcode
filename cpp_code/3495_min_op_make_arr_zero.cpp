class Solution {
private:
    long long func(long long n) {
        long long t = 1;
        int i = 1;
        long long res = 0;
        while (t <= n) {
            long long l = t * 4 - 1;
            if (l > n)
                l = n;
            l = l - t + 1;
            res += l * i;
            i ++;
            t *= 4;
        }
        return res;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for (int i = 0; i < queries.size(); ++ i) {
            int l = queries[i][0];
            int r = queries[i][1];
            long long s = func(r) - func(l - 1);
            long long m = func(r) - func(r - 1);
            long long t = (s + 1) >> 1;
            if (t < m)
                res += m;
            else
                res += t;
        }
        return res;
    }
};
