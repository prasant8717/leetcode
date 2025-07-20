struct Trie {
    unordered_map<string, shared_ptr<Trie>> um;
    bool d;
};

class Solution {
private:
    shared_ptr<Trie> rtr = make_shared<Trie>();
    string subtrie_path(shared_ptr<Trie> tr,
        unordered_map<string, vector<shared_ptr<Trie>>>& str) {
        string st = "(";
        for (auto& [s, ctr] : tr->um)
            st += s + subtrie_path(ctr, str);
        st += ")";
        if (st != "()")
            str[st].push_back(tr);
        return st;
    }
    void bld_path(shared_ptr<Trie> tr, vector<string>& ps,
                     vector<vector<string>>& vs) {
        for (auto& [s, ctr] : tr->um)
            if (ctr->d == false) {
                ps.push_back(s);
                bld_path(ctr, ps, vs);
                ps.pop_back();
            }
        if (ps.empty() == 0)
            vs.push_back(ps);
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        vector<vector<string>> out;
        unordered_map<string, vector<shared_ptr<Trie>>> umt;
        ranges::sort(paths);
        for (int i = 0; i < paths.size(); ++ i) {
            shared_ptr<Trie> tr = rtr;
            for (int j = 0; j < paths[i].size(); ++ j) {
                string s = paths[i][j];
                if (tr->um.contains(s) == 0)
                    tr->um[s] = make_shared<Trie>();
                tr = tr->um[s];
            }
        }
        subtrie_path(rtr, umt);
        for (auto& [_, ctr] : umt)
            if (ctr.size() > 1)
                for (shared_ptr<Trie> tr : ctr)
                    tr->d = true;
        vector<string> ps;
        bld_path(rtr, ps, out);
        return out;
    }
};
