class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26);
        int t = 0;
        for (int i = 0; i < tasks.size(); ++ i) {
            char c = tasks[i] - 'A';
            ++ v[c];
             if (t < v[c])
                t = v[c];
        }
        int k = 0;
        for (int i = 0; i < v.size(); ++ i)
            k += (v[i] == t);
        int res = tasks.size();
        int j = (t - 1) * (n + 1) + k;
        if (res < j)
            res = j;
        return res;
    }
};
