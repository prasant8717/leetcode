class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();
        queue<vector<int>> que{{entrance}};
        maze[entrance[0]][entrance[1]] = '+';
        int step = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!que.empty()) {
            ++step;
            for (int cnt = que.size(); cnt > 0; --cnt) {
                auto pos = que.front();
                que.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = pos[0] + dir[i];
                    int y = pos[1] + dir[i + 1];
                    if (x >= 0 && x < row && y >= 0 &&
                            y < col && maze[x][y] == '.') {
                        if (x == 0 || x == row - 1 || y == 0 || y == col - 1)  
                            return step;
                        que.push({x, y});
                        maze[x][y] = '+';
                    }
                }
            }
        }
        return -1;        
    }
};
