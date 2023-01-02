class Solution {
public:
    int helper(int row,vector<vector<int>>& grid,int prev, vector<vector<int>>&dp){
        if(row==grid.size()){
            return 0;
        }
        if(prev!=-1&&dp[row][prev]!=-1){
            return dp[row][prev];
        }
        int sum = 1e6;
        for(int i = 0; i<grid.size(); i++){
            if(i!=prev){
                sum=min(grid[row][i]+helper(row+1,grid,i,dp),sum);
            }
        }
        if(prev!=-1) dp[row][prev]=sum;
        return sum;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid.size(),-1));
        return helper(0,grid,-1,dp);
    }
};