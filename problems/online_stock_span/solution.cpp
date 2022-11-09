class StockSpanner {
    vector<int> v;
public:
    StockSpanner() {
        v = {};
    }
    
    int next(int price) {
        v.push_back(price);
        int count = 0;
        int i = v.size()-1;
        while(i>=0&&v[i]<=price){
            count++;
            i--;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */