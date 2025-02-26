class Solution {
private:
    int n;
    vector<int> cnt;
    vector<int> path;

    bool search(int u) {
        if (u == n * 2)
            return 1;
        if (path[u] != 0)
            return search(u + 1);
        for (int i = n; i > 1; -- i) {
            if ((cnt[i] != 0) &&
                (u + i < n * 2) &&
                (path[u + i] == 0)) {
                path[u] = i;
                path[u + i] = i;
                cnt[i] = 0;
                if (search(u + 1) != 0)
                    return 1;
                cnt[i] = 2;
                path[u] = 0;
                path[u + i] = 0;
            }
        }
        if (cnt[1] != 0) {
            path[u] = 1;
            cnt[1] = 0;
            if (search(u + 1) != 0)
                return 1;
            cnt[1] = 1;
            path[u] = 0;
        }
        return 0;
    }

public:
    vector<int> constructDistancedSequence(int x) {
        n = x;
        cnt.resize(n * 2, 2);
        path.resize(n * 2);
        cnt[1] = 1;
        search(1);
        vector<int> out;
        for (int i = 1; i < n * 2; ++ i)
            out.push_back(path[i]);
        return out;
    }
};
