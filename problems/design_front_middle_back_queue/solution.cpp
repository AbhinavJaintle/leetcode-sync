class FrontMiddleBackQueue {
    list<int> l;
public:
    FrontMiddleBackQueue() {
        l={};
    }
    
    void pushFront(int val) {
        l.push_front(val);
    }
    
    void pushMiddle(int val) {
        int i=l.size()/2;
        
        list <int> n;
        if(l.size()==0)n.push_front(val);
        else{
        while(l.size()){
            if(i==0){
                n.push_back(val);
            }
            n.push_back(l.front());
            l.pop_front();
            i--;
        }
        }
        l=n;
    }
    
    void pushBack(int val) {
        l.push_back(val);
    }
    
    int popFront() {
        if(l.size()==0)return -1;
        int temp=l.front();
        l.pop_front();
        return temp;
    }
    
    int popMiddle() {
        if(l.size()==0)return -1;
        int i;
        if(l.size()%2!=0){
            i=l.size()/2;
        }
        else{
            i=l.size()/2-1;
        }
        list <int> n;
        int temp;
        while(l.size()){
            if(i==0){
                temp=l.front();
                l.pop_front();
            }
            if(!l.size())continue;
            n.push_back(l.front());
            l.pop_front();
            i--;
        }
        l=n;
        return temp;
    }
    
    int popBack() {
        if(l.size()==0)return -1;
        int temp = l.back();
        l.pop_back();
        return temp;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */