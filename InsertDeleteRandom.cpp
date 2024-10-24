class RandomizedSet {
public:
    bool insert(int val) {
        if (idx.contains(val))
            return false;
        idx[val] = v.size();
        v.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (idx.contains(val) == 0)
            return false;
        const int id = idx[val];
        idx[v.back()] = id;
        idx.erase(val);
        v[id] = v.back();
        v.pop_back();
        return true;
    }

    int getRandom() {
        int id = rand() % v.size();
        return v[id];
    }

 private:
    unordered_map<int, int> idx;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
