class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ct = isConnected.size();
        int pcnt = 0;
        bool vis[ct];
        for (int i = 0; i < ct; ++i) {
            vis[i] = false;
        }
        std::function<void(int)> search = [&](int cidx) {
            vis[cidx] = true;
            for (int j = 0; j < ct; ++j) {
                if (vis[j] == false && isConnected[cidx][j]) {
                    search(j);
                }
            }
        };
        for (int i = 0; i < ct; ++i) {
            if (vis[i] == false) {
                search(i);
                ++pcnt;
            }
        }
        return pcnt;        
    }
};
