class BinIdxTree {
private:
    int n;
    vector<int> v;

public:
    BinIdxTree(int k)
        : n(k)
        , v(k + 1) {}

    void update(int t, int d) {
        while (t <= n) {
            v[t] += d;
            t += lowbit(t);
        }
    }

    int query(int t) {
        int i = 0;
        while (t > 0) {
            i += v[t];
            t -= lowbit(t);
        }
        return i;
    }

    int lowbit(int t) {
        return t & -t;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        vector<int> vi(us.begin(), us.end());
        ranges::sort(vi);
        unordered_map<int, int> um;
        int n = vi.size();
        for (int i = 0; i < n; ++ i)
            um[vi[i]] = i + 1;
        BinIdxTree* tree = new BinIdxTree(n);
        vector<int> out(nums.size());
        for (int i = nums.size() - 1; i >= 0; -- i) {
            int t = um[nums[i]];
            tree->update(t, 1);
            out[i] = tree->query(t - 1);
        }
        return out;
    }
};
