class Solution {
public:
    void helper(int index, int k, int n, vector<int>& curr, vector<vector<int>>& ans){
        if(index>n+1){
            return;
        }
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        curr.push_back(index);
        helper(index+1,k,n,curr,ans);
        curr.pop_back();
        helper(index+1,k,n,curr,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> ans;
        helper(1,k,n,curr,ans);
        return ans;
    }
};