class Solution {
public:
    string sortVowels(string s) {
        string res;
        vector<char> vc;
        constexpr string_view sv = "aeiouAEIOU";
        for (int i = 0; i < s.size(); ++ i) {
            if (sv.find(s[i]) != string_view::npos)
                vc.push_back(s[i]);
        }
        ranges::sort(vc);
        int i = 0;
        for (char c : s)
            if (sv.find(c) != string_view::npos)
                res += vc[i ++];
            else
                res += c;
        return res;
  }
};
