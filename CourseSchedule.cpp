class Solution {
public:
    enum status {
        S_NOT_TAKEN,
        S_TAKING,
        S_TAKEN
    };
    bool check_status(vector<vector<int>>& tc, int i, vector<status>& st) {
        if (st[i] == S_TAKING)
            return true;
        if (st[i] == S_TAKEN)
            return false;
        st[i] = S_TAKING;
        for (int j = 0; j < tc[i].size(); ++ j) {
            if (check_status(tc, tc[i][j], st))
                return true;
        }
        st[i] = S_TAKEN;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> tc(numCourses);
        vector<status> st(numCourses);
        for (int i = 0; i < prerequisites.size(); ++ i) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            tc[v].push_back(u);
        }
        for (int i = 0; i < numCourses; ++ i) {
            if (check_status(tc, i, st))
                return false;
        }
        return true;
    }
};
