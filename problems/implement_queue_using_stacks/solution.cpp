class MyQueue {
public:
    stack<int> p;
    stack<int> r;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        p.push(x);
    }
    
    int pop() {
        while(!p.empty()){
            r.push(p.top());
            p.pop();
        }
        int x = r.top();
        r.pop();
        while(!r.empty()){
            p.push(r.top());
            r.pop();
        }
        return x;
    }
    
    int peek() {
        while(!p.empty()){
            r.push(p.top());
            p.pop();
        }
        int x = r.top();
        while(!r.empty()){
            p.push(r.top());
            r.pop();
        }
        return x;
    }
    
    bool empty() {
        return p.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */