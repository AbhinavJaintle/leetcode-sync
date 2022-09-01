class Solution {
    
public:
    int dfs(int x, int y, vector<vector<int>>& matrix, int curr,int count,vector<vector<int>>& dp){
        if(x<0||y<0||x>matrix.size()-1||y>matrix[0].size()-1||matrix[x][y]<=curr){
            return count;
        }
        if(dp[x][y]!=-1){
            return count+dp[x][y];
        }
        int ans = max({dfs(x-1,y,matrix,matrix[x][y],count+1,dp),dfs(x+1,y,matrix,matrix[x][y],count+1,dp),dfs(x,y-1,matrix,matrix[x][y],count+1,dp),dfs(x,y+1,matrix,matrix[x][y],count+1,dp)});
        dp[x][y] = ans-count;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans = -1*(1e+5);
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                ans=max(ans,dfs(i,j,matrix,-1,0,dp));
            }
        }
        return ans;
    }
};