class MyStack {
public:
    queue<int> q;
    queue<int> r;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int x = q.back();
        int n = q.size();
        for(int i = 0; i<n-1; i++){
            r.push(q.front());
            q.pop();
        }
        q.pop();
        int m = r.size();
        for(int j = 0; j<m; j++){
            q.push(r.front());
            r.pop();
        }
        return x;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */