class Solution {
public:
    int numCoin(int index, int target, vector<int>& coins,int curr,vector<vector<int>>&dp){
        if(curr==target){
            return 0;
        }
        if(index>=coins.size()||curr>target){
            return 1e+6;
        }
        if(dp[curr][index]!=-1){
            return dp[curr][index];
        }
        int ans; 
        if(coins[index]>target){
            ans = numCoin(index+1,target,coins,curr,dp);
        }
        else{
     ans = min({1+numCoin(index+1,target,coins,curr+coins[index],dp),numCoin(index+1,target,coins,curr,dp),1+numCoin(index,target,coins,curr+coins[index],dp)});
        }
        return dp[curr][index]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
        int ret = numCoin(0,amount,coins,0,dp);
        if(ret>1e+5){
            return -1;
        }
        return ret;
    }
};