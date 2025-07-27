class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream is(sentence);
        vector<string> vs;
        string s;
        while (getline(is, s, ' ')) {
            vs.push_back(s);
        }
        for (int i = 0; i < vs.size(); ++ i) {
            if (vs[i].back() != vs[(i + 1) % vs.size()][0])
                return false;
        }
        return true;
    }
};
