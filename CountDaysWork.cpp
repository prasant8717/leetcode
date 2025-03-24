class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        ranges::sort(meetings);
        int res = 0;
        int c = 0;
        for (int i = 0; i < meetings.size(); ++ i) {
            int s = meetings[i][0];
            int e = meetings[i][1];
            if (c < s)
                res += s - c - 1;
            if (c < e)
                c = e;
        }
        res += days - c;
        return res;
    }
};
