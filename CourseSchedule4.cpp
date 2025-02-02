class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> vb(numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < prerequisites.size(); ++ i) {
            vb[prerequisites[i][0]][prerequisites[i][1]] = true;
        }
        for (int k = 0; k < numCourses; ++ k) {
            for (int i = 0; i < numCourses; ++ i) {
                for (int j = 0; j < numCourses; ++ j) {
                    bool b = (vb[i][k] && vb[k][j]);
                    vb[i][j] = vb[i][j] | b;
                }
            }
        }
        vector<bool> out;
        for (int i = 0; i < queries.size(); ++ i) {
            out.push_back(vb[queries[i][0]][queries[i][1]]);
        }
        return out;
    }
};
