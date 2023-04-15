class Solution {
public:
    int helper(int index, vector<vector<int>>& piles, int k,int curr, vector<vector<int>>& dp){
        if(curr==k){
            return 0;
        }
        if(index==piles.size())return 0;
        if(dp[index][curr])return dp[index][curr];
        int maxi=helper(index+1,piles,k,curr,dp);
        for(int i = 1; i<=k-curr&&i<=piles[index].size(); i++){
            maxi=max(maxi,piles[index][i-1]+helper(index+1,piles,k,curr+i,dp));
        }
        return dp[index][curr]=maxi;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(piles.size(),vector<int>(k,0));
        for(auto&i:piles){
            int prev=0;
            for(auto&j:i){
                j+=prev;
                prev=j;
            }
        }
        return helper(0,piles,k,0,dp);
    }
};