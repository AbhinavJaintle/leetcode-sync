class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int helper(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(dp[x][y]!=-1)return dp[x][y];
        int ans = 1;
        for(auto&i:dirs){
            if(x+i[0]<0||x+i[0]>=grid.size()||y+i[1]<0||y+i[1]>=grid[0].size()||grid[x+i[0]][y+i[1]]<=grid[x][y])continue;
            ans=(ans+helper(x+i[0],y+i[1], grid, dp))%1000000007;
        }
        return dp[x][y]=ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int sum = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                sum = (sum+helper(i,j,grid,dp))%1000000007;
            }
        }
        return sum;
    }
};