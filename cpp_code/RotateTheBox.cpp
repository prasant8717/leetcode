class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> out(n, vector<char>(m));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                out[j][m - i - 1] = box[i][j];
            }
        }
        for (int i = 0; i < m; ++ i) {
            queue<int> q;
            for (int j = n - 1; ~j; -- j) {
                if (out[j][i] == '*') {
                    queue<int> t = q;
                    q = queue<int>();
                } else if (out[j][i] == '.') {
                    q.push(j);
                } else if (q.empty() == 0) {
                    out[q.front()][i] = '#';
                    q.pop();
                    out[j][i] = '.';
                    q.push(j);
                }
            }
        }
        return out;
    }
};
