class Solution {
public:
    string defangIPaddr(string address) {
        string out = "";
        for (int i = 0; i < address.length(); ++ i) {
            if (address[i] == '.')
                out += "[.]";
            else
                out += address[i];
        }
        return out;
    }
};
