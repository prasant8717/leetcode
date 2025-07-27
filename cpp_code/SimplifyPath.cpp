class Solution {
public:
    string simplifyPath(string path) {
        string out;
        istringstream ss(path);
        vector<string> v;
        while (ss.eof() == 0) {
            string str;
            getline(ss, str, '/');
            if ((str.empty() != 0) || (str == ".")) {
                continue;
            }
            if (str == "..") {
                if (v.empty() == 0) {
                    v.pop_back();
                }
            } else {
                v.push_back(str);
            }
        }
        for (int i = 0; i < v.size(); ++ i) {
            out += "/" + v[i];
        }
        return (out.empty() != 0) ? "/" : out;
    }
};
