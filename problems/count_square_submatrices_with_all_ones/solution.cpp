class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int num = 0;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(i==0||j==0){
                    dp[i][j]=matrix[i][j];
                    num+=dp[i][j];
                }
            }
        }
        for(int i = 1; i<matrix.size(); i++){
            for(int j = 1; j<matrix[0].size(); j++){
                if(matrix[i][j]==1){
                dp[i][j] = 1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                num+= dp[i][j];
                }
            }
        }
        return num;
    }
};