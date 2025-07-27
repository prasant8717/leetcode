class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ranges::sort(robot);
        ranges::sort(factory);
        vector<vector<long long>> distance(robot.size(), vector<long long>(factory.size()));
        function<long long(int i, int j)> compute = [&](int i, int j) -> long long {
            if (i == robot.size())
                return 0;
            if (j == factory.size())
                return 1e15;
            if (distance[i][j])
                return distance[i][j];
            long long res = compute(i, j + 1);
            long long t = 0;
            for (int k = 0; k < factory[j][1]; ++ k) {
                if ((i + k) >= robot.size())
                    break;
                t += abs(robot[i + k] - factory[j][0]);
                res = min(res, t + compute(i + k + 1, j + 1));
            }
            distance[i][j] = res;
            return res;
        };
        return compute(0, 0);
    }
};
