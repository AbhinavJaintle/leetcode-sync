class Solution {
public:
    unordered_map<int,int> dp;
    int ncr(int n){
        if(n==1||n==0)return dp[n]=1;
        if(dp[n])return dp[n];
        int sum=0;
        for(int i = 1; i<=n; i++){
            sum+=ncr(i-1)*ncr(n-i);
        }
        return dp[n]=sum;
    }
    int numTrees(int n) {
        ncr(n);
        return dp[n];
    }
};