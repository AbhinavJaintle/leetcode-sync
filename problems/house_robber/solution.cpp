class Solution {
public:
    
    int robber(int index, int curr, vector<int>& nums, vector<int>& dp){
        if(index>=nums.size()){
            return curr;
        }
        if(dp[index]!=-1){
            return curr + dp[index];
        }
        int ops1 = robber(index+1, curr, nums, dp);
        int ops2 = robber(index+2, curr+nums[index], nums, dp);
        return dp[index] = max(ops1,ops2);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[nums.size()-1] = nums[nums.size()-1];
        return robber(0, 0, nums, dp);
    }
};