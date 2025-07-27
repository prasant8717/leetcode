class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        if (month < 3) {
            month += 12;
            year -= 1;
        }
        int c = year / 100;
        year %= 100;
        int d = ((c >> 2) - (c << 1) +
                 year + (year >> 2) + (13 * (month + 1) / 5) +
                 (day - 1)) % 7;
        vector<string> ws = {"Sunday", "Monday",
                                "Tuesday", "Wednesday",
                                "Thursday", "Friday",
                                "Saturday"};
        return ws[(d + 7) % 7];
    }
};
