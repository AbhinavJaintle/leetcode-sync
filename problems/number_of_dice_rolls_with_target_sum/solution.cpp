class Solution {
    long long MOD = 1e9+7;
public:
    int dice(int index, int n, int k, int target, int curr, vector<vector<int>>& dp){
        if(index==n){
            if(curr==target){
                return 1;
            }
            return 0;
        }
        if(dp[index][curr]!=-1){
            return dp[index][curr];
        }
        if(curr>target){
            return 0;
        }
        int ans = 0;
        for(int i =1; i<=k; i++){
            ans = (ans+dice(index+1,n,k,target,curr+i,dp))%MOD;
        }
        return dp[index][curr] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(n*k+1,-1));
        return dice(0,n,k,target,0,dp);
    }
};