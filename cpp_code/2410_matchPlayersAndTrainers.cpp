class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        ranges::sort(players);
        ranges::sort(trainers);
        int m = players.size();
        int n = trainers.size();
        int j = 0;
        for (int i = 0; i < m; ++ i) {
            while ((j < n) && (trainers[j] < players[i])) {
                ++ j;
            }
            if (j == n) {
                return i;
            }
            ++ j;
        }
        return m;
    }
};
