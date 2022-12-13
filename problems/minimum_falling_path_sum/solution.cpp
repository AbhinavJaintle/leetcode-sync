class Solution {
public:
    int pathSum(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp){
        if(row==matrix.size()){
            return 0;
        }
        if(col<0||col>matrix[0].size()-1){
            return 1e7;
        }
        if(dp[row][col]!=0){
            return dp[row][col];
        }
        return dp[row][col] = matrix[row][col]+min({pathSum(matrix,row+1,col,dp),pathSum(matrix,row+1,col-1,dp),pathSum(matrix,row+1,col+1,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int sum = 1e7;
        for(int i = 0; i<matrix[0].size(); i++){
            sum=min(sum,pathSum(matrix,0,i,dp));
        }
        return sum;
    }
};