class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (duration == 0)
            return 0;
        int res = 0;
        for (int i = 0; i < timeSeries.size() - 1; ++ i) {
            int d = timeSeries[i + 1] - timeSeries[i];
            if (d < duration) {
                res += d;
            } else {
                res += duration;
            }
        }

    return res + duration;
  }
};
