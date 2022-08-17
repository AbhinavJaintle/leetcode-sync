class Solution {
public:
     void per(vector<int> nums, vector<vector<int>> &ans, int id){
        if(id == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = id; i < nums.size(); i++){
            if(i != id && nums[i] == nums[id])
                continue;
            swap(nums[i], nums[id]);
            per(nums, ans, id+1);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        per(nums, ans, 0);
        return ans;
    }
};