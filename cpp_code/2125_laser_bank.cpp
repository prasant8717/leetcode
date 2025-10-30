class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        int n = 0;
        for (int i = 0; i < bank.size(); ++ i) {
            int k = ranges::count(bank[i], '1');
            if (k > 0) {
                res += n * k;
                n = k;
            }
        }
        return res;
    }
};
