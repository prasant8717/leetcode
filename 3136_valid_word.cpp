class Solution {
private:
    static bool vowel(char c) {
        string_view sv = "aeiouAEIOU";
        return sv.find(c) != string_view::npos;
    }

    static bool consonant(char c) {
        return isalpha(c) && (vowel(c) == false);
    }

public:
    bool isValid(string word) {
        bool sts = word.length() >= 3;
        sts = sts && ranges::all_of(word, [](char c) { return isalnum(c); });
        sts = sts && ranges::any_of(word, vowel) &&
                     ranges::any_of(word, consonant);
        return sts;
    }
};
