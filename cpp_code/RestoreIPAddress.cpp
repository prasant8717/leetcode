class Solution {
public:
    void get_ip_addr(string inp, int i, int j, int lvl, string tmp,
           vector<string>& out)
    {
        if (i == (j + 1) && lvl == 5) {
            out.push_back(tmp.substr(1));
        }
        for (int k = i; k < i + 3 && k <= j; k++) {
            string aa = inp.substr(i, k - i + 1);
            if ((inp[i] == '0'&&aa.size()>1) || stol(aa) > 255)
                return;
            get_ip_addr(inp, k + 1, j, lvl + 1, tmp + '.' + aa, out);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string> out; 
        get_ip_addr(s, 0, n - 1, 1, "", out);
        return out;        
    }
};
