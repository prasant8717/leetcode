class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vs;
        for (int i = 1; i <= n; ++ i) {
            string s;
            if (i % 15 == 0)
                s = "FizzBuzz";
            else if (i % 5 == 0)
                s = "Buzz";
            else if (i % 3 == 0)
                s = "Fizz";
            else
                s = to_string(i);
            vs.push_back(s);
        }
        return vs;
    }
};
