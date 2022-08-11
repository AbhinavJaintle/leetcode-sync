class Solution {
public:
    
    void sub(vector<int> nums, int index, vector<int> temp, vector<vector<int>>& ans){
        if(index>=nums.size()){
            return;
        }
        sub(nums, index+1, temp, ans);
        temp.push_back(nums[index]);
        ans.push_back(temp);
        sub(nums, index+1, temp, ans);
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        vector<int> temp;
        sub(nums,0,temp, ans);
        return ans;
    }
};