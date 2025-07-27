class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int l = bits.size();
        int c = 0;
        for (; c < l - 1; )
            c += bits[c] + 1;
        return (c == (l - 1));
    }
};
