class SmallestInfiniteSet {
    unordered_map<int,int> m;
    int mini = 1;
public:
    SmallestInfiniteSet() {
        m.clear();
    }
    
    int popSmallest() {
        int temp=mini;
        m[mini]++;
        int index=1;
        while(m[index]!=0)index++;
        mini=index;
        return temp;
    }
    
    void addBack(int num) {
        m[num]=0;
        mini=min(mini,num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */