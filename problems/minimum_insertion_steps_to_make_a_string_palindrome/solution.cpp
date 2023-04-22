class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        for(int i = s.length()-2; i>=0; i--){
            for(int j = i+1; j<s.length(); j++){
                if(s[i]==s[j])dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][s.length()-1];
    }
};