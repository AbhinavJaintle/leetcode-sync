class MyCalendar {
public:
    map<int,int> m;
        
    MyCalendar() {
        m.clear();
    }
    
    bool book(int start, int end) {
        for(auto i = m.begin(); i!=m.end(); i++){
            if((start<=i->first&&i->first<end)||(i->first<=start&&start<i->second)){
                return false;
            }
        }
        m[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */