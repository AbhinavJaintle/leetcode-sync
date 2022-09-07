class Solution {
public:
    int islands(int x, int y, vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]==0||dp[x][y]==1){
            return 0;
        }
        dp[x][y]=1;
        int ans = 1+islands(x+1,y,dp,grid)+islands(x-1,y,dp,grid)+islands(x,y+1,dp,grid)+islands(x,y-1,dp,grid);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(dp[i][j]==0){
                    ans = max(ans,islands(i,j,dp,grid));
                }
            }
        }
        return ans;
    }
};