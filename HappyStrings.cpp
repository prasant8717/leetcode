class Solution {
public:
    string getHappyString(int n, int k) {
        queue<string> qs{{{"a", "b", "c"}}};
        unordered_map<char, string> umcs { {'a', "bc"},
                                           {'b', "ac"},
                                           {'c', "ab"} };
        while (qs.front().length() != n) {
            string t = qs.front();
            qs.pop();
            for (char ch : umcs.at(t.back()))
                qs.push(t + ch);
        }
        if (qs.size() < k)
            return "";
        for (int i = 0; i < k - 1; ++ i)
            qs.pop();
        return qs.front();
    }
};
