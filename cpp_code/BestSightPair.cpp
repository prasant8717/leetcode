class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0;
        int m = 0;
        for (int i = 0; i < values.size(); ++ i) {
            int t = m + values[i] - i;
            if (res < t)
                res = t;
            int a = values[i] + i;
            if (m < a)
                m = a;
        }
        return res;
    }
};
