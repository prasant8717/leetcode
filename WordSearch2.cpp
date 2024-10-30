struct trie {
  vector<shared_ptr<trie>> tr;
  string *s = nullptr;
  trie() : tr(26) {}
};

class Solution {
public:
    void search(shared_ptr<trie>& tr, vector<vector<char>>& board, vector<string>& o, int i, int j) {
        if ((i < 0) || (i == board.size())) {
            return;
        }
        if ((j < 0) || (j == board[0].size())) {
            return;
        }
        if (board[i][j] == '*')
            return;
        char c = board[i][j];
        shared_ptr<trie> tmp = tr->tr[c - 'a'];
        if (tmp == nullptr)
            return;
        if (tmp->s != nullptr) {
            o.push_back(*tmp->s);
            tmp->s = nullptr;
        }
        board[i][j] = '*';
        search(tmp, board, o, i + 1, j);
        search(tmp, board, o, i - 1, j);
        search(tmp, board, o, i, j + 1);
        search(tmp, board, o, i, j - 1);
        board[i][j] = c;
    }
    void insert(string& s, shared_ptr<trie>& tr) {
        shared_ptr<trie> n = tr;
        for (char c : s) {
            int i = c - 'a';
            if (n->tr[i] == nullptr)
                n->tr[i] = make_shared<trie>();
            n = n->tr[i];
        }
        n->s = &s;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> vs;
        shared_ptr<trie> trr = make_shared<trie>();
        for (string& s : words)
            insert(s, trr);
        for (int i = 0; i < board.size(); ++ i)
            for (int j = 0; j < board[0].size(); ++ j)
                search(trr, board, vs, i, j);
        return vs;        
    }
};
