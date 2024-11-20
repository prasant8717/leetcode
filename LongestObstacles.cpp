class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> out;
        int l = obstacles.size();
        vector<int> vt;
        for (int i = 0; i < l; ++ i)
            if ((vt.empty() != 0) || (obstacles[i] >= vt.back())) {
                vt.push_back(obstacles[i]);
                out.push_back(vt.size());
            } else {
                int t = ranges::upper_bound(vt, obstacles[i]) - vt.begin();
                vt[t] = obstacles[i];
                out.push_back(t + 1);
            }
        return out;
    }
};
