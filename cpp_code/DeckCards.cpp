class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> um;
        for (int i = 0; i < deck.size(); ++ i)
            ++ um[deck[i]];
        int t = um[deck[0]];
        for (auto [_, k] : um)
            t = gcd(t, k);
        return t >= 2;        
    }
};
