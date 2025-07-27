class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int res = 0;
        int sum = 0;
        unordered_set<int> us{banned.begin(), banned.end()};
        for (int i = 1; i <= n; ++ i)
            if (us.contains(i) == 0)
                if (sum + i <= maxSum) {
                    sum += i;
                    ++ res;
                }
        return res;
    }
};
