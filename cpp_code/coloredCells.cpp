class Solution {
public:
    long long coloredCells(int n) {
        long long s = n;
        return (s * s) + (s -1) * (s - 1);
    }
};
