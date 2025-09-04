class Solution {
public:
    long long flowerGame(int n, int m) {
        return static_cast<long>(n >> 1) * ((m + 1) >> 1) +
               static_cast<long>(m >> 1) * ((n + 1) >> 1);
    }
};
