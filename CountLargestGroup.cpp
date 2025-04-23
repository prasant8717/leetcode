class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> vc(40);
        int res = 0;
        int m = 0;
        for (int i = 1; i <= n; ++ i) {
            int t = 0;
            for (int k = i; k != 0; k /= 10)
                t += k % 10;
            ++ vc[t];
            int j = vc[t];
            if (m < j) {
                m = j;
                res = 1;
            } else if (m == j)
                ++ res;
        }
        return res;
    }
};
