class Solution {
public:
    vector<string> belowTwenty = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string frame_str(int num) {
        string s;
        if (num < 20)
            s = belowTwenty.at(num);
        else if (num < 100)
            s = tens.at(num / 10) + " " + belowTwenty.at(num % 10);
        else if (num < 1000)
            s = frame_str(num / 100) + " Hundred " + frame_str(num % 100);
        else if (num < 1000000)
            s = frame_str(num / 1000) + " Thousand " + frame_str(num % 1000);
        else if (num < 1000000000)
            s = frame_str(num / 1000000) + " Million " + frame_str(num % 1000000);
        else
            s = frame_str(num / 1000000000) + " Billion " + frame_str(num % 1000000000);
        erase(s);
        return s;
    }
    void erase(string& s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        return frame_str(num);
    }
};
