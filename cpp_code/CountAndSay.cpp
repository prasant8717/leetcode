class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        while (-- n) {
            string tmp = "";
            for (int i = 0; i < str.length();) {
                int j = i;
                while ((j < str.size()) && (str[j] == str[i]))
                    ++ j;
                tmp += to_string(j - i);
                tmp += str[i];
                i = j;
            }
            str = tmp;
        }
        return str;        
    }
};
