class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xz = abs(x - z);
        int yz = abs(y - z);
        int res = 0;
        if (xz < yz)
            res = 1;
        if (xz > yz)
            res = 2;
        return res;
    }
};
