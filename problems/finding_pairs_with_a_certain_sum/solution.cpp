class FindSumPairs {
public:
    vector<int> n1, n2;
    unordered_map<int,int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1;
        n2=nums2;
        sort(n1.begin(),n1.end());
        m.clear();
        for(auto&i:n2){
            m[i]++;
        }
    }
    
    void add(int index, int val) {
        m[n2[index]]--;
        n2[index]+=val;
        m[n2[index]]++;

    }
    
    int count(int tot) {
        int sum=0;
        for(auto&i:n1){
            if(i>=tot)break;
            sum+=m[tot-i];
        }
        return sum;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */