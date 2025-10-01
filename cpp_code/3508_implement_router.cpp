struct data_pkt {
    int src;
    int dst;
    int tm;

    bool operator<(const data_pkt& dp) const {
        return (src < dp.src) || ((src == dp.src) && (dst < dp.dst)) ||
           (src == dp.src) && (dst == dp.dst) && (tm < dp.tm);
    }
};

class Router {
private:
    map<int, vector<int>> dstm;
    map<int, int> pktm;
    set<data_pkt> pkts;
    queue<data_pkt> qpkt;
    int lm;

public:
    Router(int memoryLimit) : lm(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        data_pkt pkt{source, destination, timestamp};
        if (pkts.find(pkt) != pkts.end())
            return false;
        if (qpkt.size() == lm)
            forwardPacket();
        qpkt.push(pkt);
        pkts.insert(pkt);
        dstm[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (qpkt.empty())
            return {};
        data_pkt npkt = qpkt.front();
        qpkt.pop();
        pkts.erase(npkt);
        ++ pktm[npkt.dst];
        return {npkt.src, npkt.dst, npkt.tm};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (dstm.find(destination) == dstm.end())
            return 0;
        vector<int>& tm = dstm[destination];
        int idx = pktm[destination];
        auto lb = lower_bound(tm.begin() + idx, tm.end(), startTime);
        auto ub = upper_bound(tm.begin() + idx, tm.end(), endTime);
        return ub - lb;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
