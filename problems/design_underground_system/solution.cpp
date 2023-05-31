class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> m;
    map<pair<string,string>,pair<int,int>> s;
    UndergroundSystem() {
        m.clear();
        s.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int ans = t-m[id].second;
        s[{m[id].first,stationName}].first+=ans;
        s[{m[id].first,stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans = (double)s[{startStation,endStation}].first/s[{startStation,endStation}].second;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */