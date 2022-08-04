class Solution {
public:
    
  int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        dp[grid.size()-1][grid[0].size()-1] = grid[grid.size()-1][grid[0].size()-1];
        for(int i = grid.size()-1; i>=0; i--){
            for(int j = grid[0].size()-1;j>=0;j--){
                if(dp[i][j]==-1){
                int ops1 = (i+1>grid.size()-1) ? 10e+3:dp[i+1][j];
                int ops2 = (j+1>grid[0].size()-1) ? 10e+3:dp[i][j+1];
                dp[i][j] = grid[i][j]+min(ops1,ops2);
                }
            }
        }
        return dp[0][0];
    }
};