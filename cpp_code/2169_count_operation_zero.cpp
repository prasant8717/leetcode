class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;
        for (; ;) {
            if (!num1 || !num2)
                break;
            if (num1 >= num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            ++ res;
        }
        return res;
    }
};
