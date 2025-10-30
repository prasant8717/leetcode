class Solution {
private:
    bool isBalanced(int n) {
        vector<int> vd(11);
        for (int i = n; i != 0; i /= 10) {
            if (i % 10 == 0)
                return false;
            vd[i % 10] ++;
        }
        bool sts = true;
        for (int i = 1; i < 10; ++ i) {
            if (vd[i] && (vd[i] != i)) {
                sts = false;
                break;
            }
        }
        return sts;
    }
public:
    int nextBeautifulNumber(int n) {
        int res = -1;
        for (int i = n + 1; i < INT_MAX; ++ i) {
            if (isBalanced(i) == true) {
                res = i;
                break;
            }
        }
        return res;
    }
};
