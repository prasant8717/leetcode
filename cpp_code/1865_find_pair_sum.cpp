class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        for (int i = 0; i < nums2.size(); ++ i) {
            ++ um[nums2[i]];
        }
    }

    void add(int index, int val) {
        -- um[v2[index]];
        v2[index] += val;
        ++ um[v2[index]];
    }

    int count(int tot) {
        int res = 0;
        for (int i = 0; i < v1.size(); ++ i) {
            res += um[tot - v1[i]];
        }
        return res;
    }

private:
    vector<int> v1;
    vector<int> v2;
    unordered_map<int, int> um;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
