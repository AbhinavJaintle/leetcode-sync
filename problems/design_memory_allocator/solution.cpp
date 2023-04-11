class Allocator {
    map<int,vector<int>> m1;
    unordered_map<int,int> m2;
    int sz;
    int curr;
public:
    Allocator(int n) {
        m1.clear();
        m2.clear();
        sz=n;
        curr=sz;
    }
    
    int allocate(int size, int mID) {
        if(size>curr)return -1;
        for(int i = 0; i<=sz-size; i++){
            bool flag=true;
            for(int j = i; j<i+size; j++){
                if(m2[j]){
                    i=j;
                    flag=false;
                    break;
                }
            }
            if(flag){
            for(int j = i; j<i+size; j++){
                m2[j]++;
                m1[mID].push_back(j);
            }
            curr-=size;
            return i;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int sum=m1[mID].size();
        curr+=sum;
        for(auto&i:m1[mID]){
            m2[i]--;
        }
        m1[mID]={};
        return sum;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */