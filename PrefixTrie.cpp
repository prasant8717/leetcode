class Trie {
public:
    vector<string> vstr;
    int end;
    Trie() {
        end = 0;
    }
    
    void insert(string word) {
        vstr.push_back(word);
        end ++;
    }
    
    bool search(string word) {
        for (int i = 0; i < end; ++i) {
            if (word == vstr[i]) {
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for (int i = 0; i < end; ++i) {
            if (vstr[i].find(prefix) == 0) {
                return true;
            }
        }
        return false;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
