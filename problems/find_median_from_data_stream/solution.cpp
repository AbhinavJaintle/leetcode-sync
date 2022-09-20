class MedianFinder {
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> big;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.empty()||num<small.top()){
            small.push(num);
        }
        else{
            big.push(num);
        }
        if(small.size()>big.size()+1){
            big.push(small.top());
            small.pop();
        }
        else if(big.size()>small.size()+1){
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if((small.size()+big.size())%2!=0){
            return small.size()>big.size() ? small.top() : big.top();
        }
        else{
            return ((double)small.top()+(double)big.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */