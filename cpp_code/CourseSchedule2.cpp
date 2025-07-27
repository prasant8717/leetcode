class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> tc(numCourses);
        vector<int> nc(numCourses);
        for (int i = 0; i < prerequisites.size(); ++ i) {
            int j = prerequisites[i][0];
            int k = prerequisites[i][1];
            tc[k].push_back(j);
            ++ nc[j];
        }
        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (nc[i] == 0) {
                que.push(i);
            }
        }
        vector<int> res;
        while (que.empty() == 0) {
            int i = que.front();
            que.pop();
            res.push_back(i);
            for (int j = 0; j < tc[i].size(); ++ j) {
                if (-- nc[tc[i][j]] == 0) {
                    que.push(tc[i][j]);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();        
    }
};
