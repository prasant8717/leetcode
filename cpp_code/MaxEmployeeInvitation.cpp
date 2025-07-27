class Solution {
public:
    int get_cycle(vector<int>& v) {
        int n = v.size();
        vector<bool> vt(n);
        int ret = 0;
        for (int i = 0; i < n; ++ i) {
            if (vt[i] != 0)
                continue;
            vector<int> vc;
            int j = i;
            while (vt[j] == 0) {
                vc.push_back(j);
                vt[j] = true;
                j = v[j];
            }
            for (int k = 0; k < vc.size(); ++ k) {
                if (vc[k] == j) {
                    int t = vc.size() - k;
                    if (ret < t)
                        ret = t;
                    break;
                }
            }
        }
        return ret;
    }
    int get_sort(vector<int>& v) {
        int n = v.size();
        vector<int> vi(n);
        vector<int> vd(n, 1);
        for (int i = 0; i < n; ++ i)
            ++vi[v[i]];
        queue<int> q;
        for (int i = 0; i < n; ++ i)
            if (vi[i] == 0)
                q.push(i);
        while (q.empty() == 0) {
            int i = q.front();
            q.pop();
            if (vd[v[i]] < vd[i] + 1)
                vd[v[i]] = vd[i] + 1;
            if (-- vi[v[i]] == 0)
                q.push(v[i]);
        }
        int ret = 0;
        for (int i = 0; i < n; ++ i)
            if (i == v[v[i]])
                ret += vd[i];
        return ret;
    }
    int maximumInvitations(vector<int>& favorite) {
        int c = get_cycle(favorite);
        int s = get_sort(favorite);
        return (s < c) ? c : s;
    }
};
