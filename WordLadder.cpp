class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us(wordList.begin(), wordList.end());
        queue<string> que{{beginWord}};
        int res = 1;
        while (que.empty() == 0) {
            ++ res;
            for (int i = que.size(); i > 0; -- i) {
                string str = que.front();
                que.pop();
                for (int j = 0; j < str.size(); ++ j) {
                    char c = str[j];
                    for (char k = 'a'; k <= 'z'; ++ k) {
                        str[j] = k;
                        if (us.count(str) == 0)
                            continue;
                        if (str == endWord)
                            return res;
                        que.push(str);
                        us.erase(str);
                    }
                    str[j] = c;
                }
            }
        }
        return 0;        
    }
};
