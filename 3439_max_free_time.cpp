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
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                  vector<int>& endTime) {
        vector<int> v = check(eventTime, startTime, endTime);
        int s = accumulate(v.begin(), v.begin() + k + 1, 0);
        int res = s;
        for (int i = k + 1; i < v.size(); ++ i) {
            s += v[i] - v[i - k - 1];
            if (res < s)
                res = s;
        }
        return res;
    }
};
