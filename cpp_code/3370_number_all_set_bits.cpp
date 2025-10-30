class Solution {
public:
    int smallestNumber(int n) {
        int res = 1;
        for (int i = 1; i < 11; ++ i) {
            if (res < n) {
                res = (1 << i) - 1; 
            } else {
                break;
            }
        }
        return res;
    }
};
