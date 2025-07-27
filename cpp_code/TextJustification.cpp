class Solution {
public:
    string join(const vector<string>& words, const string& s) {
        string str;
        for (int i = 0; i < words.size(); ++i) {
            str += words[i];
            if (i != words.size() - 1)
                str += s;
            }
        return str;
    }

    string ljust(string s, int width) {
        for (int i = 0; i < s.length() - width; ++i)
            s += " ";
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vout;
        vector<string> line;
        int len = 0;
        for (string& str : words) {
            if (len + line.size() + str.length() > maxWidth) {
                int emp = maxWidth - len;
                if (line.size() == 1) {
                    for (int i = 0; i < emp; ++ i)
                        line[0] += " ";
                } else {
                    for (int i = 0; i < emp; ++ i)
                        line[i % (line.size() - 1)] += " ";
                }
                vout.push_back(join(line, ""));
                line.clear();
                len = 0;
            }
            line.push_back(str);
            len += str.length();
        }
        vout.push_back(ljust(join(line, " "), maxWidth));
        return vout;
    }
};
