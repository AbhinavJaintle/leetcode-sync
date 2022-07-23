class NumberContainers {
public:
    map<int, int> m;
    map<int,int>::iterator itr;
    
    NumberContainers() {
        m.clear();
    }
    
    void change(int index, int number) {
        m.insert(pair<int,int>(index, number));
        m[index] = number;
    }
    
    int find(int number) {
        for(itr = m.begin(); itr != m.end(); ++itr){
            if(itr->second == number){
                return itr->first;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */