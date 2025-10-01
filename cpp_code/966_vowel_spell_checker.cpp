class Solution {
private:
    string lower(string& wd) {
        string s{"$"};
        for (int i = 0; i < wd.length(); ++ i)
            s += tolower(wd[i]);
        return s;
    }
    string vowel(string& wd) {
        string s;
        for (int i = 0; i < wd.size(); ++ i)
            s += is_vowel(wd[i]) ? '*' : tolower(wd[i]);
        return s;
    }
    bool is_vowel(char c) {
        string sv = "aeiouAEIOU";
        return sv.find(c) != string::npos;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist,
                            vector<string>& queries) {
        unordered_map<string, string> um;
        vector<string> out;
        for (int i = 0; i < wordlist.size(); ++ i) {
            string s = wordlist[i];
            um.insert({s, s});
            um.insert({lower(s), s});
            um.insert({vowel(s), s});
        }
        for (int i = 0; i < queries.size(); ++ i) {
            string s = queries[i];
            auto it1 = um.find(s);
            auto it2 = um.find(lower(s));
            auto it3 = um.find(vowel(s));
            if (it1 != um.cend())
                out.push_back(it1->second);
            else if (it2 != um.cend())
                out.push_back(it2->second);
            else if (it3 != um.cend())
                out.push_back(it3->second);
            else
                out.push_back("");
        }
        return out;
    }
};
