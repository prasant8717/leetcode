class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> um;
        for (int i = 0; i < wall.size(); ++ i) {
            long long t = 0;
            for (int j = 0; j < wall[i].size() - 1; ++ j) {
                t += wall[i][j];
                um[t] ++;
            }
        }
        int m = 0;
        for (auto i : um) {
            if (m < i.second)
                m = i.second;
        }
        return wall.size() - m;
    }
};
