class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            ranges::sort(stones, [](int a, int b) {
                                        return a < b;
                                        });
            int n = stones.size();
            if (stones[n - 1] == stones[n - 2]) {
                stones.pop_back();
            } else {
                stones[n - 2] = stones[n - 1] - stones[n - 2];
            }
            stones.pop_back();
        }
        if (stones.size() == 0)
            return 0;
        return stones[0];
    }
};
