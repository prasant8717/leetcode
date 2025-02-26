class NumberContainers {
private:
    unordered_map<int, int> um;
    unordered_map<int, set<int>> ums;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (um.contains(index) != 0) {
            int oldNumber = um[index];
            ums[oldNumber].erase(index);
            if (ums[oldNumber].empty() != 0) {
                ums.erase(oldNumber);
            }
        }
        um[index] = number;
        ums[number].insert(index);
    }
    
    int find(int number) {
        int ret = -1;
        if (ums.contains(number) != 0)
            ret = *ums[number].begin();
        return ret;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
