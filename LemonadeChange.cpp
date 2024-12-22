class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int t = 0;
        int f = 0;
        for (int i = 0; i < bills.size(); ++ i) {
            if (bills[i] == 5) {
                ++ f;
            } else if (bills[i] == 10) {
                ++ t;
                -- f;
            } else {
                if (t != 0) {
                    -- t;
                    -- f;
                } else {
                    f -= 3;
                }
            }
            if (f < 0) {
                return false;
            }
        }
        return true;        
    }
};
