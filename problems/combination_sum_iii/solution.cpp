class Solution {
public:
    vector<vector<int>> v={};
    void helper(int index, int k, int n, int curr, vector<int> prev){
        if(prev.size()==k){
            if(curr==n)v.push_back(prev);
            return;
        }
        if(index==10||curr>n)return;
        for(int i = index; i<10; i++){
            prev.push_back(i);
            helper(i+1,k,n,curr+i,prev);
            prev.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> prev;
        helper(1,k,n,0,prev);
        return v;
    }
};