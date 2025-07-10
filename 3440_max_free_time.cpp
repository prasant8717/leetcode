class Solution {
private:
    vector<int> check(int et, vector<int>& vs, vector<int>& ve) {
        vector<int> v{vs[0]};
        for (int i = 1; i < vs.size(); ++ i)
            v.push_back(vs[i] - ve[i - 1]);
        v.push_back(et - ve.back());
        return v;
  }

public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> v = check(eventTime, startTime, endTime);
        vector<int> vl(n + 1);
        vector<int> vr(n + 1);
        int res = 0;
        vl[0] = v[0];
        vr[n] = v[n];
        for (int i = 1; i < n + 1; ++ i)
            if (v[i] < vl[i - 1])
                vl[i] = vl[i - 1];
            else
                vl[i] = v[i];
        for (int i = n - 1; i >= 0; -- i)
            if (v[i] < vr[i + 1])
                vr[i] = vr[i + 1];
            else
                vr[i] = v[i];
        for (int i = 0; i < n; ++ i) {
            int t1 = (i > 0) ? vl[i - 1] : 0;
            int t2 = (i + 2) < (n + 1) ? vr[i + 2] : 0;
            if (t1 < t2)
                t1 = t2;
            int ct = endTime[i] - startTime[i];
            int s = v[i] + v[i + 1];
            if (ct <= t1)
                t1 = s + ct;
            else
                t1 = s;
            if (res < t1)
                res = t1;
        }
        return res;
    }
};
