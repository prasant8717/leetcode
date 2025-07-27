// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1)
            return isBadVersion(1);
        int l = 1;
        int r = n;
        while (l < r) {
            int m = ((long long)l + r) / 2;
            if (isBadVersion(m) == true) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
