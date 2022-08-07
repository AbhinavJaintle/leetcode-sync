class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long int>> dp(n, vector<long long int>(5, 0));
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
        dp[0][3] = 1;
        dp[0][4] = 1;
        long long int mode = 1000000007;
        for(int i = 1; i<n; i++){
            dp[i][1] = (dp[i][1]+dp[i-1][0]+dp[i-1][2])%(mode);
            dp[i][0] = (dp[i][0] +dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%(mode);
            dp[i][2] = (dp[i][2] + dp[i-1][1]+dp[i-1][3])%(mode);
            dp[i][3] = (dp[i][3] +dp[i-1][2])%(mode);
            dp[i][4] = (dp[i][4] +dp[i-1][2]+dp[i-1][3])%(mode);
            
        }
        return (dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+dp[n-1][3]+dp[n-1][4])%(mode);
    } 
};