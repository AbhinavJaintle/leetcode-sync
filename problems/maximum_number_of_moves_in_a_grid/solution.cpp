class Solution {
    vector<vector<int>> dirs = {{0,1},{-1,1},{1,1}};
public:
    int helper(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(dp[r][c]!=-1)return dp[r][c];
        int val = grid[r][c];
        int ans=0;
        for(auto&i:dirs){
            if(r+i[0]>=0&&r+i[0]<grid.size()&&c+i[1]>=0&&c+i[1]<grid[0].size()&&grid[r+i[0]][c+i[1]]>val){
                ans=max(ans,1+helper(r+i[0],c+i[1],grid,dp));
            }
        }
        return dp[r][c]=ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int maxi=0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i = 0; i<grid.size(); i++){
            maxi=max(maxi,helper(i,0,grid,dp));
        }
        return maxi;
    }
};