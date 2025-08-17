class Solution {
public:
    int maximum69Number (int num) {
        int d0 = num % 10;
        int d1 = (num / 10) % 10;
        int d2 = (num / 100) % 10;
        int d3 = (num / 1000);
        if (d3 == 6)
            d3 = 9;
        else if (d2 == 6)
            d2 = 9;
        else if (d1 == 6)
            d1 = 9;
        else if (d0 == 6)
            d0 = 9;
        return (d3 * 1000 + d2 * 100 + d1 * 10 + d0);
    }
};
