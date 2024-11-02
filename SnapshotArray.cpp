class SnapshotArray {
public:
    vector<vector<pair<int, int>>> vs;
    int sz;
    SnapshotArray(int length) {
        vs.resize(length);
        sz = 0;
    }
    
    void set(int index, int val) {
        vs[index].emplace_back(sz, val);
    }
    
    int snap() {
        int res = sz;
        sz ++;
        return res;
    }
    
    int get(int index, int snap_id) {
        pair<int, int> p = {snap_id, INT_MAX};
        auto val = upper_bound(vs[index].begin(), vs[index].end(), p);
        return val == vs[index].begin() ? 0 : prev(val)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
