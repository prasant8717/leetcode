struct trie {
  vector<shared_ptr<trie>> tr;
  int sts;
  trie() : tr(26) {}
};

class WordDictionary {
public:
    shared_ptr<trie> root;
    WordDictionary() {
        root = make_shared<trie>();
    }
    
    void addWord(string word) {
        shared_ptr<trie> n = root;
        for (char c : word) {
            if (n->tr[c - 'a'] == nullptr)
                n->tr[c - 'a'] = make_shared<trie>();
            n = n->tr[c - 'a'];
        }
        n->sts = 1;
    }
    
    bool search_str(shared_ptr<trie> r, string& s, int p) {
        if (p == s.size()) {
            return r->sts == 1;
        }
        if (s[p] != '.') {
            shared_ptr<trie> tmp = r->tr[s[p] - 'a'];
            return tmp != nullptr ? search_str(tmp, s, p + 1) : false;
        }
        for (int i = 0; i < 26; ++ i)
            if ((r->tr[i] != nullptr) && (search_str(r->tr[i], s, p + 1) == true))
                return true;
        return false;
    }
    bool search(string word) {
        return search_str(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
