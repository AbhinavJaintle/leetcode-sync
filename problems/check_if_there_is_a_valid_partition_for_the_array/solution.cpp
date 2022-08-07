class Solution {
public:
    bool part(int index, vector<int>& nums, vector<int>& dp){
        if(index>nums.size()){
            return false;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        bool b1 = false;
        bool b2 = false;
        bool b3 = false;
        
        if((index+1)<nums.size()&&nums[index]==nums[index+1]){
            b1 = part(index+2, nums, dp);
        }
        if((index+2)<nums.size()){
        
        if(nums[index]==nums[index+1]&&nums[index]==nums[index+2]){
            b2 = part(index+3, nums, dp);
        }
        else if(nums[index+1]-nums[index]==1&&nums[index+2]-nums[index+1]==1){
            b3 = part(index+3, nums, dp);
        }
        }
        if(b1||b2||b3){
            return dp[index] = true;
        }
        return dp[index] = false;
    }
    
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        dp[nums.size()]=1;
        return part(0,nums,dp);
    }
};