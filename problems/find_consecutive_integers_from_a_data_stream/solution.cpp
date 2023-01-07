class DataStream {
    int n = 0;
    int prev=-1;
    int val;
    int w;
public:
    DataStream(int value, int k) {
        val=value;
        w=k;
    }
    
    bool consec(int num) {
        n++;
        if(num!=val) prev=n;
        return n<w?false:n-prev+1>w;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */