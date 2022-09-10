class Solution {
public:
    int stocks(int index, int k, vector<int>& prices, int flag, int count, vector<vector<vector<int>>>& dp){
        if(count==k){
            return 0;
        }
        if(index>prices.size()-1){
            return 0;
        }
        if(dp[index][flag][count]!=-1){
            return dp[index][flag][count];
        }
        int ans;
        if(flag==0){
            ans = max(-prices[index]+stocks(index+1,k,prices,1,count,dp),stocks(index+1,k,prices,0,count,dp));
        }
        else{
            ans = max(prices[index]+stocks(index+1,k,prices,0,count+1,dp),stocks(index+1,k,prices,1,count,dp));
        }
        return dp[index][flag][count]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return stocks(0,k,prices,0,0,dp);
    }
};