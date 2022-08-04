class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        dp[nums.size()-1] = 1;
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i]==0){
                dp[i]=0;
                continue;
            }
            
            int flag = 0;
            
            for(int j = 1; j<nums[i]+1&&(j+i<nums.size()); j++){
                if(dp[i+j]==1){
                    dp[i]=dp[i+j];
                    flag++;
                    break;
                }
            }
            if(flag==1){
                continue;
            }
            dp[i]=0;
        }
        return dp[0];
    }
};