class Solution {
public:
    int distMoney(int money, int children) {
        int res = 0;
        if (money < children)
            res = -1;
        else if (money > (children << 3))
            res = children - 1;
        else if (money == ((children << 3) - 4))
            res = children - 2;
        else
            res = (money - children) / 7;
        return res;
    }
};
