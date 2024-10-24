class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        int row[] = { -1, 0, 1, 0 };
        int col[] = { 0, 1, 0, -1 };
        int vis[n][m];
        queue<pair<pair<int, int>, int> > q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({ { i, j }, 0});
                    vis[i][j] = 2; 
                }
                else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    cnt++; 
            }
        }
        int rcnt = 0;
        int tm = 0;
        while (!q.empty()) {
            int r = q.front().first.first; 
            int c = q.front().first.second; 
            int t = q.front().second; 
            q.pop();
            tm = max(tm, t);
            for (int i = 0; i < 4; i++) {
                int nr = r + row[i];
                int nc = c + col[i];
                if (nr >= 0 && nr < n && nc >= 0
                        && nc < m && grid[nr][nc] == 1
                        && vis[nr][nc] != 2) {
                    vis[nr][nc] = 2;
                    q.push({ { nr, nc }, t + 1 }); 
                    rcnt++;
                }
            }
        }
        return (rcnt == cnt) ? tm : -1;        
    }
};
