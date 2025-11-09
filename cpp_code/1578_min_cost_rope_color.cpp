class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int m = neededTime[0];
        for (int i = 1; i < colors.size(); ++ i) {
            if (colors[i] == colors[i - 1]) {
                res += min(neededTime[i], m);
                m = max(neededTime[i], m);
            } else {
                m = neededTime[i];
            }
        }
        return res;
    }
};
