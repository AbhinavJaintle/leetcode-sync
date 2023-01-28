class SummaryRanges {
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_map<int,int> vis;
public:
    SummaryRanges() {
        vis.clear();
        pq=priority_queue<int,vector<int>,greater<int>>();
    }
    
    void addNum(int value) {
        if(!vis[value])pq.push(value);
        vis[value]++;
    }
    
    vector<vector<int>> getIntervals() {
        if(!pq.size())return {};
        int prev=pq.top()-1;
        vector<vector<int>> v;
        vector<int> temp={pq.top()};
        priority_queue<int,vector<int>,greater<int>> curr=pq;
        while(!curr.empty()){
            if(curr.top()!=prev+1){
                temp.push_back(prev);
                v.push_back(temp);
                temp={curr.top()};
                prev=curr.top();
            }
            prev=curr.top();
            curr.pop();
        }
        temp.push_back(prev);
        v.push_back(temp);
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */