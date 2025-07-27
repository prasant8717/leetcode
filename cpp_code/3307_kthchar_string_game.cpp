class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int oc = ceil(log2(k));
        int d = 0;
        for (int i = oc - 1; i >= 0; -- i) {
            long long t = 1L << i;
            if (k > t) {
                k -= t;
                d += operations[i];
            }
        }
        return 'a' + (d % 26);
    }
};
