class Router {
public:
    using state = tuple<int,int,int>;

    struct Hash {
        size_t operator()(const state& t) const {
            auto [a, b, c] = t;
            return hash<int>()(a) ^ (hash<int>()(b) << 1) ^ (hash<int>()(c) << 2);
        }
    };

    int maxSize;
    deque<state> dq;
    unordered_set<state, Hash> st;
    unordered_map<int, deque<int>> mpp;

    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }

    void deleteFrontPacket() {
        auto temp = dq.front();

        int temp_des = get<1>(temp);

        dq.pop_front();
        st.erase(temp);
        mpp[temp_des].pop_front();
    }

    bool addPacket(int source, int destination, int timestamp) {
        state packet = {source, destination, timestamp};

        if(st.find(packet) != st.end())
            return false;

        if(dq.size() == maxSize)
            deleteFrontPacket();

        dq.push_back(packet);
        st.insert(packet);
        mpp[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if(dq.empty())
            return {};

        auto pkt = dq.front();
        deleteFrontPacket();

        return {get<0>(pkt), get<1>(pkt), get<2>(pkt)};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto &temp = mpp[destination];

        auto i = lower_bound(temp.begin(), temp.end(), startTime);
        auto j = upper_bound(temp.begin(), temp.end(), endTime);

        return j - i;
    }
};