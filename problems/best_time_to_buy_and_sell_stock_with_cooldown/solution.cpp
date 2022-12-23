class Solution {
public:
    int prof(int index, int curr, int sum, int flag, vector<int>& prices, vector<vector<int>>& dp){
        if(index==prices.size()){
            return 0;
        }
        int ans;
        if(flag!=1&&dp[index][flag]!=-1){
            return dp[index][flag];
        }
        if(flag==2){
            ans = prof(index+1,curr,sum,0,prices,dp);
        }
        if(flag==0){
            ans = max(prof(index+1,curr,sum,0,prices,dp),prof(index+1,prices[index],sum,1,prices,dp));
        }
        if(flag==1){
            ans = max(prof(index+1,curr,sum,1,prices,dp),prices[index]-curr+prof(index+1,curr,sum,2,prices,dp));
        }
        return dp[index][flag] = ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(3,-1));
        return prof(0,0,0,0,prices,dp);
    }
};