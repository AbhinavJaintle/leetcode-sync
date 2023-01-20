class Solution {
    vector<vector<int>> ans={};
public:
    void helper(int index, vector<int>& nums, map<vector<int>,int>& m,vector<int>& curr, int prev){
        if(index==nums.size()){
            if(!m[curr]&&curr.size()>1){
                ans.push_back(curr);
                m[curr]++;
            }
            return;
        }
        if(nums[index]>=prev){
            curr.push_back(nums[index]);
            helper(index+1,nums,m,curr,nums[index]);
            curr.pop_back();
        }
        helper(index+1,nums,m,curr,prev);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        map<vector<int>,int> m;
        vector<int> curr;
        helper(0,nums,m,curr,-200);
        return ans;
    }
};