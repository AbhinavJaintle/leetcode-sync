class Solution {
public:
    int helper(int curr, vector<int>& coins, int start, vector<vector<int>>& dp){
        if(curr==0){
            return 1;
        }
        if(start==coins.size()||curr<0)return 0;
        if(dp[start][curr]!=-1)return dp[start][curr];
        int ans = 0;
        int temp;
        for(int i = start; i<coins.size()&&curr>=coins[i]; i++){
            temp=curr;
            while(temp>=0){
                temp-=coins[i];
                ans+=helper(temp,coins,i+1,dp);
            }
        }
        return dp[start][curr] = ans;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        return helper(amount,coins,0, dp);
    }
};