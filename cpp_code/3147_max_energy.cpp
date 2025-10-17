class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> ve(energy);
        for (int i = energy.size() - 1 - k; i >= 0; -- i)
            ve[i] += ve[i + k];
        return ranges::max(ve);
    }
};
