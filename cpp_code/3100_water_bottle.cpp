class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        for (; ;) {
            if (numBottles < numExchange) 
                break;
            numBottles = (numBottles - numExchange + 1);
            ++ numExchange;
            ++ res;
        }
        return res;
    }
};
