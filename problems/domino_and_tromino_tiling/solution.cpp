class Solution {
public:
    long long int recurse(int col, int filled,vector<vector<long long int>> &dp){
        int n = dp.size();
        if(col >= n || (col==n-1 && filled==0)) return 1;
        if(col == n-1 && filled == 1) return 0;

        if(dp[col][filled] != -1) return dp[col][filled];
        if(filled == 0){
                return dp[col][filled] = (recurse(col+2,0,dp)+(2*recurse(col+1,1,dp))+recurse(col+1,0,dp))%1000000007;
        }
        else{
            return dp[col][filled]= (recurse(col+1,1,dp) + recurse(col+2,0,dp))%1000000007;
        }

        return 0;
    }
    int numTilings(int n) {
        vector<vector<long long int>> dp(n,vector<long long int>(2,-1));

        return recurse(0,0,dp);

    }
};