class Solution {
public:
    int helper(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp){
        if(x==grid.size()-1){
            return grid[x][y];
        }
        if(dp[x][y]!=-1)return dp[x][y];
        int ans = 1e9;
        for(int i =0; i<grid[0].size(); i++){
            ans=min(ans,grid[x][y]+moveCost[grid[x][y]][i]+helper(x+1,i,grid,moveCost,dp));
        }
        return dp[x][y] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans = 1e9;
        for(int i =0; i<grid[0].size(); i++){
            ans=min(ans,helper(0,i,grid,moveCost,dp));
        }
        return ans;
    }
};