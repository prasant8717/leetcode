class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int sz = board.size();
        queue<int> que{{1}};
        vector<bool> vis(1 + sz * sz);
        vector<int> num(1 + sz * sz);
        for (int i = 0; i < sz; ++ i)
            for (int j = 0; j < sz; ++ j)
                num[(sz - 1 - i) * sz + ((sz - i) % 2 == 0 ? sz - j : j + 1)] = board[i][j];
        for (int i = 1; que.empty() == 0; ++ i)
            for (int j = que.size(); j > 0; -- j) {
                int tmp = que.front();
                que.pop();
                for (int k = tmp + 1; k <= min(tmp + 6, sz * sz); ++ k) {
                    int n = num[k] > 0 ? num[k] : k;
                    if (n == sz * sz)
                        return i;
                    if (vis[n] == true)
                        continue;
                    que.push(n);
                    vis[n] = true;
                }
            }
        return -1;        
    }
};
