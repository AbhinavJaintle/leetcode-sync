class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        int ans = 0;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(i==0||j==0){
                    dp[i][j]=matrix[i][j]-'0';
                    ans=max(ans,dp[i][j]);
                }
                else if(matrix[i][j]=='1'){
                    dp[i][j] = 1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        
        return ans*ans;
    }
};